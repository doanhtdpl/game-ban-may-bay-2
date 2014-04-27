#include "Background.h"

Background::Background()
{
	// do nothing
}

Background::Background( char* fileName )
{
	// load image into 2 instance
	if( fileName )
	{
		cocos2d::CCSize winSize	=	cocos2d::CCDirector::sharedDirector()->getWinSize();
		this->fCenterX			=	winSize.width/2;
		this->fCenterY			=	winSize.height/2;
		this->fdbCenterY		=	3 * this->fCenterY;

		inst1	=	cocos2d::CCSprite::create( fileName );
		float scaleX, scaleY;
		scaleX	=	winSize.width/inst1->boundingBox().size.width;
		scaleY	=	winSize.height/inst1->boundingBox().size.height;

		inst1->setScaleX( scaleX );
		inst1->setScaleY( scaleY );
		inst1->setPosition( ccp( fCenterX, fCenterY ) );
		addChild( inst1 );

		inst2	=	cocos2d::CCSprite::create( fileName );
		inst2->setPosition( ccp( fCenterX, fdbCenterY ) );
		inst2->setScaleX( scaleX );
		inst2->setScaleY( scaleY );
		addChild( inst2 );
	}

	// Init velocity scrolling
	this->fVx	=	0.f;
	this->fVy	=	-2.f;

	scheduleUpdate();
}

Background::~Background()
{
	if( inst1)
	{
		removeChild( inst1 );
		CC_SAFE_RELEASE( inst1 );
	}

	if( inst2 )
	{
		removeChild( inst2 );
		CC_SAFE_RELEASE( inst2 );
	}
}

void Background::update( float delta )
{
	// First instance
	cocos2d::CCPoint inst1Pos	=	inst1->getPosition();
	if( inst1Pos.y <= -fCenterY )
	{
		inst1Pos.y	=	fdbCenterY;
	}
	inst1Pos.x		+=	fVx;
	inst1Pos.y		+=	fVy;
	inst1->setPosition( inst1Pos );

	// Second instance
	cocos2d::CCPoint inst2Pos	=	inst2->getPosition();
	if( inst2Pos.y <= -fCenterY )
	{
		inst2Pos.y	=	fdbCenterY;
	}
	inst2Pos.x		+=	fVx;
	inst2Pos.y		+=	fVy;
	inst2->setPosition( inst2Pos );
}