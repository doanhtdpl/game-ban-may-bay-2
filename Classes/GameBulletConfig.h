#ifndef __GAME_BULLET_CONFIG_H_
#define __GAME_BULLET_CONFIG_H_

#include "ConfigInfo.h"
#include <vector>

class GameBulletConfig : public ConfigInfo
{
public:
	GameBulletConfig();
	~GameBulletConfig();

	bool insert( std::string bucket, std::string component );

public:
	char* strType;
	int number;
	std::vector<std::string> childs;
	std::vector<float> posxs;
	std::vector<float> posys;
	float fTime;
};

#endif