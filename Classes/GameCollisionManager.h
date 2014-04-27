#ifndef __GAME_COLLISION_MANAGER_H_
#define __GAME_COLLISION_MANAGER_H_

#include "cocos2d.h"
#include "BaseGameComponentsManager.h"

class GameObject;

class GameCollisionManager : public BaseGameComponentsManager
{
public:
	GameCollisionManager();
	~GameCollisionManager();

	bool insert( GameObject *goj );
	void remove( GameObject *goj );

	void onUpdate( float deltaTime );

public:

protected:
	// Sub-function from onUpdate
	virtual void onCheckCollision( float deltaTime );

	// Sub-function from onUpdate
	virtual void onApplyCollision( float deltaTime );

	// Sub-function form onUpdate
	virtual void onRemoveDead( float deltaTime );
private:
	cocos2d::CCArray	*gojs;
};

#endif // __GAME_COLLISION_MANAGER_H_