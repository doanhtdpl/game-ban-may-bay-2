#ifndef __GAME_MANAGER_H_
#define __GAME_MANAGER_H_

#include "cocos2d.h"
#include "GameCollisionManager.h"

class GameManager : public cocos2d::CCLayer, BaseGameComponentsManager
{
public:
	GameManager();
	~GameManager();

	bool insert( GameObject *goj );
	void remove( GameObject *goj );

	void onUpdate( float deltaTime );

protected:
	// Game Object container
	cocos2d::CCArray *gojs;

	// 
	GameCollisionManager collisionManager;
private:

};

#endif