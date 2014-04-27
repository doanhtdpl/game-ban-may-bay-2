#include "AirEnemy.h"

#include "Constant.h"
#include "ShareMacros.h"
#include "Config.h"
#include "ConfigObj.h"
#include "GameScene.h"
#include "AirPlaneConfig.h"
#include "ImagesConfig.h"
#include "BulletConfig.h"
#include "Bullet.h"
#include "EffectPlayer.h"

AirEnemy::AirEnemy()
{
}

AirEnemy::AirEnemy( char* cptrId ) : GameEnemy()
{
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
// 
// 	cocos2d::CCString *str	=	cocos2d::CCString::createWithFormat("dimension is ::::::::::    %d", airPlaneConf->iDirection);
// 	cocos2d::CCLabelTTF *label	=	cocos2d::CCLabelTTF::create( str->getCString(),"arial", 10 );
// 	addChild( label );

	// Config velocity
	this->velocity		=	ccp( 0.f, airPlaneConf->fVelocity * airPlaneConf->iDirection );

	// Config plane's bullet
// 	if( airPlaneConf->hasBullet )
// 	{
// 		char *bulletType	=	airPlaneConf->bulletType;
// 		DATAROW rowBulletConf		=	Config::getInst()->getMetadata( STR_BULLET );
// 		BulletConfig *bulletConf	=	(BulletConfig*)((*rowBulletConf.find( bulletType )).second);
// 		ImagesConfig *imgBulletConf	=	(ImagesConfig*)((*rowImageConfig.find( bulletConf->cptrImage )).second);
// 		bulletInfo			=	new BulletInfo( bulletConf->fVelocity, imgBulletConf->fileName, bulletType, 
// 			bulletConf->fDamage, 0, bulletConf->fVelocity, imgBulletConf->fScaleX, imgBulletConf->fScaleY, imgBulletConf->fRotation, bulletConf->effectType );
// 		this->numberBullet	=	imgConf->numberBullet;
// 		bulletX1			=	imgConf->positionX1;
// 		bulletY1			=	imgConf->positionY1;
// 		timeOnFire			=	bulletConf->fTime;
// 	}

	// Init time step
	timeStep				=	0.f;

	// Update itself
	this->scheduleUpdate();
}

AirEnemy::~AirEnemy()
{
}

void AirEnemy::update( float deltaTime )
{
	if ( NOT_EMPTY( velocity.x ) || NOT_EMPTY( velocity.y ) )
	{
		float cfx = 0.0f, cfy = 0.0f;
		this->getPosition( &cfx, &cfy );
		this->setPosition( cfx + this->velocity.x*deltaTime, cfy + this->velocity.y*deltaTime );
	}

	// Check bullet out of range
	cocos2d::CCRect	bound	=	this->getBound();
	if( bound.origin.y + bound.size.height <= 0 )
	{
		this->isDead		=	true;
	}

	if( collisionList )
		collisionList->removeAllObjects();
}

bool AirEnemy::isCollideWith( GameObject *goj )
{
	Bullet *bullet	=	(Bullet*)goj;
	return bullet	!=	NULL;
}

void AirEnemy::applyCollision()
{
	for ( unsigned i = 0; i < collisionList->count(); ++i )
	{
		try
		{
			Bullet *bullet	=	(Bullet*)(collisionList->objectAtIndex( i ));
			this->hp	-=	bullet->getDamage();
		}
		catch (...)
		{
			cocos2d::CCLog( "Collision object type was not a bullet" );
		}
	}
	if( hp <= 0 )
		this->isDead	=	true;
}

void AirEnemy::saveCollideWith( GameObject *goj )
{
	this->collisionList->addObject( goj );
}