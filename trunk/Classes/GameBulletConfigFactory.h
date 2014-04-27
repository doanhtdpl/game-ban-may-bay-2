#ifndef __GAME_BULLET_CONFIG_FACTORY_H_
#define __GAME_BULLET_CONFIG_FACTORY_H_

#include "ConfigInfoFactory.h"

class GameBulletConfigFactory : public ConfigInfoFactory
{
public:
	~GameBulletConfigFactory();
	static ConfigInfoFactory* getInst();

	ConfigInfo *create();

private:
	GameBulletConfigFactory();
	static ConfigInfoFactory* inst;
};

#endif