#include "AirCraft.h"

#include "Constant.h"
#include "Config.h"
#include "GameScene.h"
#include "AirPlaneConfig.h"
#include "ImagesConfig.h"
#include "BulletConfig.h"
#include "GameBulletConfig.h"
#include "Bullet.h"

AirCraft::AirCraft( char* cptrId ) : GamePlayer()
{
	this->label = CCLabelTTF::create("Air", "arial", 12, 
		CCSizeMake(245, 32), kCCTextAlignmentCenter);
	this->addChild( label );

	// Get current air plane config
	ConfigObj *rowAirCraftConf		=	Config::getInst()->getMetadata( STR_AIRCRAFT );
	AirPlaneConfig *airPlaneConf	=	(AirPlaneConfig*)( rowAirCraftConf->getDict()->objectForKey( cptrId ) );

	// Get image config
	ConfigObj *rowImageConfig	=	Config::getInst()->getMetadata( STR_IMAGES );
	ImagesConfig *imgConf		=	(ImagesConfig*)( rowImageConfig->getDict()->objectForKey( airPlaneConf->image ));
	char *img	=	imgConf->fileName;
	// Begin load res air plane
	this->body	=	cocos2d::CCSprite::createWithSpriteFrameName( img );
	this->body->setScaleX( imgConf->fScaleX );
	this->body->setScaleY( imgConf->fScaleY );
	this->body->setRotation( imgConf->fRotation );
	if( this->body )
		this->addChild( this->body );

	// Config hp
	this->hp				=	airPlaneConf->hp;

	// Config damage
	this->damage			=	airPlaneConf->damage;

	// Config plane's bullet
	if( airPlaneConf->hasBullet )
	{
		char *bulletType	=	airPlaneConf->bulletType;
		ConfigObj *rowGBulletConf		=	Config::getInst()->getMetadata( STR_GAME_BULLET );
		ConfigObj *rowBulletConf		=	Config::getInst()->getMetadata( STR_BULLET );
		GameBulletConfig *gBulletConfig	=	(GameBulletConfig*)( rowGBulletConf->getDict()->objectForKey( bulletType ));
		for (int i = 0; i < gBulletConfig->number; ++i)
		{
			BulletConfig *bulletConf	=	(BulletConfig*)( rowBulletConf->getDict()->objectForKey( gBulletConfig->childs.at(i) ));
			ImagesConfig *imgBulletConf	=	(ImagesConfig*)( rowImageConfig->getDict()->objectForKey( bulletConf->cptrImage ));
			BulletInfo *bulletInfo		=	new BulletInfo( bulletConf->fVelocity, imgBulletConf->fileName, bulletType, bulletConf->fDamage, gBulletConfig->posxs.at(i), 
				gBulletConfig->posys.at(i), imgBulletConf->fScaleX, imgBulletConf->fScaleY, imgBulletConf->fRotation, bulletConf->effectType );
			this->bulletInfos.push_back(bulletInfo);
		}
		timeOnFire			=	gBulletConfig->fTime;
	}

	// Init time step
	timeStep				=	0.f;
	timeToChangeBullet		=	0.f;

	// Update itself
	this->scheduleUpdate();
}

AirCraft::~AirCraft()
{
}

void AirCraft::changeBulletType( char *bulletType )
{
	ConfigObj *rowImageConfig		=	Config::getInst()->getMetadata( STR_IMAGES );
	ConfigObj *rowGBulletConf		=	Config::getInst()->getMetadata( STR_GAME_BULLET );
	ConfigObj *rowBulletConf		=	Config::getInst()->getMetadata( STR_BULLET );
	GameBulletConfig *gBulletConfig	=	(GameBulletConfig*)( rowGBulletConf->getDict()->objectForKey( bulletType ));
	for (int i = 0; i < gBulletConfig->number; ++i)
	{
		BulletConfig *bulletConf	=	(BulletConfig*)( rowBulletConf->getDict()->objectForKey( gBulletConfig->childs.at(i) ));
		ImagesConfig *imgBulletConf	=	(ImagesConfig*)( rowImageConfig->getDict()->objectForKey( bulletConf->cptrImage ));
		BulletInfo *bulletInfo		=	new BulletInfo( bulletConf->fVelocity, imgBulletConf->fileName, bulletType, bulletConf->fDamage, gBulletConfig->posxs.at(i), 
			gBulletConfig->posys.at(i), imgBulletConf->fScaleX, imgBulletConf->fScaleY, imgBulletConf->fRotation, bulletConf->effectType );
		this->bulletInfos.push_back(bulletInfo);
	}
	timeOnFire			=	gBulletConfig->fTime;
}

void AirCraft::update( float delta )
{
	timeStep			+=	delta;
	timeToChangeBullet	+=	delta;

	if( timeStep >= 0.5f )
	{
		timeStep	=	0.f;
		createBullet();
	}

// 	if( timeToChangeBullet >= 10.f )
// 	{
// 		timeToChangeBullet	=	0.f;
// 
// 		char* bulletType	=	new char[4];
// 		sprintf( bulletType, "200%d", (rand()%3 + 1) );
// 		changeBulletType( bulletType );
// 	}
}

void AirCraft::createBullet()
{
	std::vector<BulletInfo*>::iterator ite	=	bulletInfos.begin();
	for ( ; ite != bulletInfos.end(); ++ite )
	{
		BulletInfo *bulletInfo	=	(BulletInfo*)(*ite);
		Bullet *bullet	=	new Bullet( *bulletInfo );
		if( this->m_pParent )
		{
			bullet->setPosition( this->getPositionX() + bulletInfo->fx,  this->getPositionY() + bulletInfo->fy );
			((GameScene*)(this->m_pParent))->addBullet(bullet);
		}
	}
}

void AirCraft::inputProcess( cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent )
{
	cocos2d::CCTouch* touch = (cocos2d::CCTouch*)( pTouches->anyObject() );
	cocos2d::CCPoint movement	=	touch->getLocation() - touch->getPreviousLocation();
	cocos2d::CCPoint currPos	=	this->getPosition();
	currPos.x		+=	movement.x;
	currPos.y		+=	movement.y;

	cocos2d::CCSize winSize	=	cocos2d::CCDirector::sharedDirector()->getWinSize();
	cocos2d::CCRect bodySize	=	body->boundingBox();

	if( currPos.x - bodySize.size.width/2 < 0 )
		currPos.x	=	bodySize.size.width/2;
	else if( currPos.x + bodySize.size.width/2 > winSize.width )
		currPos.x	=	winSize.width - bodySize.size.width/2;

	if( currPos.y - bodySize.size.height/2 < 0 )
		currPos.y	=	bodySize.size.height/2;
	else if( currPos.y + bodySize.size.height/2 > winSize.height )
		currPos.y	=	winSize.height - bodySize.size.height/2;

	this->setPosition( currPos.x, currPos.y );
}

bool AirCraft::isCollideWith( GameObject *goj )
{
	return false;
// 	if( (Bullet*)(goj) )
// 	{
// 		return true;
// 	}
}

void AirCraft::applyCollision()
{
	for ( unsigned i = 0; i < collisionList->count(); ++i )
	{
		try
		{
			this->hp	-=	((Bullet*)(collisionList->objectAtIndex( i )))->getDamage();
		}
		catch (...)
		{
			cocos2d::CCLog( "Collision object type was not a bullet" );
		}
	}
	if( hp <= 0 )
		this->isDead	=	true;
}

void AirCraft::saveCollideWith( GameObject *goj )
{
	this->collisionList->insertObject( goj, collisionList->count() );
}