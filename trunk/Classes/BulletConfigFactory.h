#ifndef __BULLET_CONFIG_FACTORY_H_
#define __BULLET_CONFIG_FACTORY_H_

#include "ConfigInfoFactory.h"

class BulletConfigFactory : public ConfigInfoFactory
{
public:
	~BulletConfigFactory();
	static ConfigInfoFactory* getInst();

	ConfigInfo *create();

private:
	BulletConfigFactory();
	static ConfigInfoFactory* inst;
};

#endif