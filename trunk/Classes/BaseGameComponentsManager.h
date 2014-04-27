#ifndef __BASE_GAME_COMPONENTS__MANAGER_H_
#define __BASE_GAME_COMPONENTS__MANAGER_H_

class GameObject;

class BaseGameComponentsManager
{
public:
	virtual bool insert( GameObject *goj ) = 0;
	virtual void remove( GameObject *goj ) = 0;

	virtual void onUpdate( float deltaTime ) = 0;
};

#endif //__BASE_GAME_COMPONENTS__MANAGER_H_