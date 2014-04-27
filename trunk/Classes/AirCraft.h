#ifndef __AIR_CRAFT_H_
#define __AIR_CRAFT_H_

#include "GamePlayer.h"
#include "BulletInfo.h"
#include "cocos2d.h"
#include <vector>

struct AirPlaneInfo;
class AirCraft : public GamePlayer
{
public:
	AirCraft( char* cptrId );
	~AirCraft();

	void update( float delta );

	// Collision method
	bool isCollideWith( GameObject *goj );
	void saveCollideWith( GameObject *goj );
	void applyCollision();

	// Input control player air craft
	void inputProcess( cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent );

	// Action fire bullet
	void createBullet();

	// Update ship bullet
	void changeBulletType( char *bulletType );
private:
	std::vector<BulletInfo*>	bulletInfos;
	float timeOnFire;
	float timeStep;
	float timeToChangeBullet;
	cocos2d::CCLabelTTF *label;

};
#endif