#ifndef __BULLET_CONFIG_H_
#define __BULLET_CONFIG_H_

#include "ConfigInfo.h"

class BulletConfig : public ConfigInfo
{
public:
	BulletConfig();
	~BulletConfig();

	bool insert( std::string bucket, std::string component );

public:
	char*	cptrId;
	char*	cptrImage;
	float	fDamage;
	float	fVelocity;
	char*	effectType;
};

#endif