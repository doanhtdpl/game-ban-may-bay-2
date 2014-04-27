#ifndef __MAINMENU_SCENE_H_
#define __MAINMENU_SCENE_H_

#include "cocos2d.h"

class MainMenuScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);
	void playGameCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(MainMenuScene);

	void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	void update( float deltaTime );

private:
	int numberLife;
	cocos2d::CCLabelTTF *lifeLabel;

	float longTime;
	float timeCounter;
	cocos2d::CCLabelTTF *timeLabel;
};

#endif