#ifndef __PARTICLE_CONFIG_FACTORY_H_
#define __PARTICLE_CONFIG_FACTORY_H_

#include "ConfigInfoFactory.h"

class ParticleConfigFactory : public ConfigInfoFactory
{
public:
	~ParticleConfigFactory();
	static ConfigInfoFactory* getInst();

	ConfigInfo *create();

private:
	ParticleConfigFactory();
	static ConfigInfoFactory* inst;
};

#endif