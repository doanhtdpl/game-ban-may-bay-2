#ifndef __GAME_OBJECT_H_
#define __GAME_OBJECT_H_

#include "cocos2d.h"

class GameObject : public cocos2d::CCNode
{
public:
	GameObject(void);
	virtual ~GameObject();

	virtual cocos2d::CCRect getBound();
	virtual bool isCollideWith( GameObject *goj );
	virtual void saveCollideWith( GameObject *goj );
	virtual void applyCollision();

	bool isAlive();
protected:
	void registerCollisionObject();

protected:
	cocos2d::CCSprite	*body;
	cocos2d::CCArray	*collisionList;
	bool isDead;

private:
};

#endif // __GAME_OBJECT_H_