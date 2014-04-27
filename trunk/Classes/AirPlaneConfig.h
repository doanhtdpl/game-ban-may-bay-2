#ifndef __AIRPLANE_CONFIG_H_
#define __AIRPLANE_CONFIG_H_

#include "ConfigInfo.h"
#include "cocos2d.h"

USING_NS_CC;


class AirPlaneConfig : public ConfigInfo
{
public:
	AirPlaneConfig();
	~AirPlaneConfig();

	bool insert( std::string bucket, std::string component );

	char* id;
	int hp;
	float damage;
	bool hasBullet;
	char* image;
	float fVelocity;
	char* bulletType;
	int iDirection;
private:

};

#endif