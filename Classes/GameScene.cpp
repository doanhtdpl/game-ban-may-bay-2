#include "GameScene.h"
#include "GameManager.h"
#include "GameCollisionManager.h"
#include "AirCraft.h"
#include "AirEnemy.h"
#include "Bullet.h"

#include <time.h>

#include "GameContainer.h"
#include "Background.h"
#include "Config.h"
#include "Constant.h"
#include "AirPlaneConfigFactory.h"
#include "BulletConfigFactory.h"
#include "GameBulletConfigFactory.h"
#include "ImagesConfigFactory.h"
#include "ParticleConfigFactory.h"

#include "EffectPlayer.h"
#include "MapContainer.h"

USING_NS_CC;

CCScene* GameScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameScene *layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(GameScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	background	=	new Background("img_bg_level_3.png");
	addChild( background );

	gm			=	new GameManager();
	addChild(gm);

	//////////////////////////////////////////////////////////////////////////
	// Load batch file --> move to intro layer
	//
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "bullet.plist" );
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "enemy.plist" );
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "ship.plist" );
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "particle.plist" );
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "wsparticle_p01.plist" );

	//////////////////////////////////////////////////////////////////////////
	// Load game config --> move to intro layer
	//
	Config::getInst()->loadCSVConfig( STR_IMAGES, ImagesConfigFactory::getInst() );
	Config::getInst()->loadCSVConfig( STR_AIRCRAFT, AirPlaneConfigFactory::getInst() );
	Config::getInst()->loadCSVConfig( STR_BULLET, BulletConfigFactory::getInst() );
	Config::getInst()->loadCSVConfig( STR_GAME_BULLET, GameBulletConfigFactory::getInst() );
	Config::getInst()->loadCSVConfig( STR_PARTICLE, ParticleConfigFactory::getInst() );

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	//////////////////////////////////////////////////////////////////////////
	// Init core game loop
	//
	gcm			=	new GameCollisionManager();

	MapContainer mapContainer =	MapContainer();
	mapContainer.readMap( "Map_1.csv" );

	// Add game effect on the top
	addChild( EffectPlayer::getInst() );

	// Hard code
 	this->airCraft	=	new AirCraft( "1001" );
	this->airCraft->setPosition( size.width/2, 50.f );
	addChild( this->airCraft );
	//gcm->insert( this->airCraft );


	timeFactor		=	0.f;

	this->setTouchEnabled( true );
	this->scheduleUpdate();

	return true;
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

void GameScene::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	if( this->airCraft )
	{
		this->airCraft->inputProcess( pTouches, pEvent );
	}
}

void GameScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
}

void GameScene::update( float deltaTime )
{
	timeFactor	+=	deltaTime;

	if( timeFactor >= 3.f )
	{
		AirEnemy *airEnemy	=	new AirEnemy( "1003" );
		if( airEnemy )
		{
			CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
			float randX = rand() % (int)visibleSize.width + 50;
			airEnemy->setPosition( ccp( randX, visibleSize.height ));
			addPlane( airEnemy );
		}
		timeFactor	=	0.f;
	}

	gcm->onUpdate( deltaTime );
}

void GameScene::addPlane( AirEnemy *enemy )
{
	addChild( enemy );
	gcm->insert( enemy );
}

void GameScene::addBullet( Bullet *bullet )
{
	addChild( bullet );
	gcm->insert( bullet );
}