#ifndef __AIR_ENEMY_H_
#define __AIR_ENEMY_H_

#include "GameEnemy.h"
#include "BulletInfo.h"

struct AirPlaneInfo;
class AirEnemy : public GameEnemy
{
public:
	AirEnemy( char* cptrId );
	~AirEnemy();

	void update( float deltaTime );

	// Collision action
	bool isCollideWith( GameObject *goj );
	void saveCollideWith( GameObject *goj );
	void applyCollision();

protected:
private:
	AirEnemy();

private:
	BulletInfo	*bulletInfo;
	int numberBullet;
	cocos2d::CCArray	bulletPositions;
	float bulletX1, bulletY1;
	float bulletX2, bulletY2;
	float timeOnFire;
	float timeStep;
};

#endif