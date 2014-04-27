#include "Bullet.h"
#include "ShareMacros.h"
#include "Config.h"
#include "ImagesConfig.h"
#include "AirEnemy.h"
#include "AirCraft.h"
#include "EffectPlayer.h"

Bullet::Bullet()
{
}

Bullet::Bullet( BulletInfo info ) : GameObject()
{
	fDamage		=	info.fDamage;
	effectType	=	info.effectType;
	velocity	=	ccp( 0, info.fVelocity );
	this->body	=	cocos2d::CCSprite::createWithSpriteFrameName( info.cptrImage );
	if( this->body )
	{
		this->setPosition( ccp( info.fx, info.fy ) );
		this->body->setScaleX( info.fScaleX );
		this->body->setScaleY( info.fScaleY );
		this->body->setRotation( info.fRotation );
		addChild( this->body );
		scheduleUpdate();
	}
}

Bullet::~Bullet()
{

}

void Bullet::update( float deltaTime )
{
	if ( NOT_EMPTY( velocity.x ) || NOT_EMPTY( velocity.y ) )
	{
		float cfx = 0.0f, cfy = 0.0f;
		this->getPosition( &cfx, &cfy );
		this->setPosition( cfx + this->velocity.x*deltaTime, cfy + this->velocity.y*deltaTime );
	}

	// Check bullet out of range
	cocos2d::CCSize winSize	=	cocos2d::CCDirector::sharedDirector()->getWinSize();
	cocos2d::CCRect winRect	=	cocos2d::CCRectMake( 0, 0, winSize.width, winSize.height );
	if( !winRect.containsPoint(this->getPosition()) )
	{
		this->isDead		=	true;
	}

	if( collisionList )
		collisionList->removeAllObjects();
}

float Bullet::getDamage()
{
	return fDamage;
}

char* Bullet::getBulletEffType()
{
	return effectType;
}

bool Bullet::isCollideWith( GameObject *goj )
{
	AirEnemy *airEnemy =	(AirEnemy*) (goj);
	if( airEnemy != NULL )
	{
		cocos2d::CCSprite *eff	=	EffectPlayer::getInst()->playEffect( this->getBulletEffType() );
		eff->setPosition( this->getPosition() );
		eff->setScaleX( 0.5f );
		eff->setScaleY( 0.5f );
		if( this->m_pParent != NULL )
		{
			this->m_pParent->addChild( eff );
		}
		return true;
	}
	return false;
}

void Bullet::applyCollision()
{
}

void Bullet::saveCollideWith( GameObject *goj )
{
	this->collisionList->insertObject( goj, collisionList->count() );
}