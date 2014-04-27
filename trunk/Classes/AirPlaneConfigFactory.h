#ifndef __ENEMY_CONFIG_FACTORY_H_
#define __ENEMY_CONFIG_FACTORY_H_

#include "ConfigInfoFactory.h"

class AirPlaneConfigFactory : public ConfigInfoFactory
{
public:
	~AirPlaneConfigFactory();
	static ConfigInfoFactory* getInst();

	ConfigInfo *create();

private:
	AirPlaneConfigFactory();
	static ConfigInfoFactory* inst;
};

#endif