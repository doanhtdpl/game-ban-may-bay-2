#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

CCScene* MainMenuScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	MainMenuScene *layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	///////////////////////////////
	// 2. menu init
	cocos2d::CCSize winSize	=	cocos2d::CCDirector::sharedDirector()->getWinSize();
	float scaleX, scaleY;

	CCSprite *background		=	CCSprite::create("menu.jpg");
	background->setPosition( ccp(winSize.width/2, winSize.height/2) );

	scaleX		=	winSize.width / background->boundingBox().size.width;
	scaleY		=	winSize.height / background->boundingBox().size.height;

	background->setScaleX( scaleX );
	background->setScaleY( scaleY );
	addChild( background );

	// create button play game
	CCLabelTTF *buttonPlay	=	CCLabelTTF::create( "tap here to play", "TechnoHideo", 15, CCSizeMake(245, 32), kCCTextAlignmentCenter );
	CCMenuItem *labelPlay	=	CCMenuItemLabel::create( buttonPlay, this, menu_selector(MainMenuScene::playGameCallback) );
	labelPlay->setPosition( ccp( winSize.width/2, (winSize.height)/6 ) );

	// Create menu with close button
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(MainMenuScene::menuCloseCallback));
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, labelPlay, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	// Init timer
	longTime		=	1.f * 60.f;

	timeCounter		=	longTime;
	timeLabel		=	CCLabelTTF::create( "", "TechnoHideo", 13, CCSizeMake(245, 32), kCCTextAlignmentCenter );
	timeLabel->setPosition( ccp( 3 * winSize.width / 6, winSize.height/8 ) );
	addChild( timeLabel );

	// Life
	// Action airplane flight in
	numberLife			=	5;

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "ship.plist" );

	CCSprite *life		=	CCSprite::createWithSpriteFrameName( "ship_0.png" );
	life->setScaleX( 0.1f );
	life->setScaleY( 0.1f );
	life->setPosition( ccp(  3 * winSize.width / 6, winSize.height / 11 ));
	addChild( life );

	lifeLabel		=	CCLabelTTF::create( "x0", "TechnoHideo", 13, CCSizeMake(245, 32), kCCTextAlignmentCenter );
	lifeLabel->setPosition( ccp( 4 * winSize.width / 6, winSize.height / 11 ) );
	addChild( lifeLabel );

	this->scheduleUpdate();

	return true;
}


void MainMenuScene::menuCloseCallback(CCObject* pSender)
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

void MainMenuScene::playGameCallback(CCObject* pSender)
{
	if( numberLife > 0 )
	{
		numberLife--;

		cocos2d::CCSize winSize	=	cocos2d::CCDirector::sharedDirector()->getWinSize();

		// Action airplane flight in
		CCSprite *airplane		=	CCSprite::createWithSpriteFrameName( "ship_0.png" );
		airplane->setRotation( 3.14f / 4 );
		airplane->setScaleX( 0.1f );
		airplane->setScaleY( 0.1f );
		airplane->setPosition( ccp( -100, winSize.height/6 ));
		addChild( airplane );

		CCMoveTo *moveAirPlane	=	CCMoveTo::create( 1, ccp( winSize.width + 100, winSize.height / 6 ) );
		airplane->runAction( moveAirPlane );

		// Action text 
		CCScaleTo *actionIn		=	CCScaleTo::create( 0.1f, 0.8f, 0.8f );
		CCScaleTo *actionOut	=	CCScaleTo::create( 0.1f, 1.0f, 1.0f );
		CCSequence *actionSum	=	CCSequence::createWithTwoActions( actionIn, actionOut );
		CCRepeatForever *repeat		=	CCRepeatForever::create( actionSum );

		CCMenuItemLabel *menuLabel	=	(CCMenuItemLabel *)pSender;
		if( pSender != NULL )
			menuLabel->runAction( repeat );

		CCDirector* pDirector = CCDirector::sharedDirector();
		CCScene *pScene = GameScene::scene();
		pDirector->replaceScene(pScene);
	}
}

void MainMenuScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
}

void MainMenuScene::update( float deltaTime )
{
	timeCounter	-=	deltaTime;

	// Update view
	unsigned minute	=	timeCounter / 60.f;
	unsigned second	=	(int)timeCounter % 60;

	char * text		=	new char[6];
	sprintf( text, "%d:%d", minute, second );
	timeLabel->setString( text );

	if( timeCounter <= 0.0f )
	{
		timeCounter		=	longTime;

		// Create new life
		numberLife++;
	}

	char* lifeTxt	=	new char[5];
	sprintf( lifeTxt, "x %d", numberLife );
	lifeLabel->setString( lifeTxt );
}