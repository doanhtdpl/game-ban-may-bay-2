#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class AirCraft;
class GameManager;
class Bullet;
class AirEnemy;
class Background;
class GameContainer;
class GameCollisionManager;

class GameScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(GameScene);

	void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	void update( float deltaTime );

	void addBullet( Bullet *bullet );
	void addPlane( AirEnemy *enemy );
private:
	// Animation background
	Background *background;

	// Game player
	AirCraft	*airCraft;

	GameManager *gm;
	GameCollisionManager *gcm;

	float timeFactor;
};

#endif // __GAME_SCENE_H__
