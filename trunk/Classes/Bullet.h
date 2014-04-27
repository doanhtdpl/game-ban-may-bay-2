#ifndef __BULLET_H_
#define __BULLET_H_

#include "GameObject.h"
#include "BulletInfo.h"

class Bullet : public GameObject
{
public:
	Bullet( BulletInfo info );
	~Bullet();

	bool isCollideWith( GameObject *goj );
	void saveCollideWith( GameObject *goj );
	void applyCollision();

	void update( float deltaTime );

public:
	float getDamage();
	char* getBulletEffType();

protected:
	void registerCollisionObject();

private:
	Bullet();
	cocos2d::CCPoint velocity;
	float fDamage;
	char* effectType;
};

#endif