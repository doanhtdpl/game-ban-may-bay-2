#include "ParticleConfigFactory.h"
#include "ParticleConfig.h"

ConfigInfoFactory* ParticleConfigFactory::inst = new ParticleConfigFactory();

ParticleConfigFactory::ParticleConfigFactory()
{
}

ParticleConfigFactory::~ParticleConfigFactory()
{
}

ConfigInfoFactory* ParticleConfigFactory::getInst()
{
	return inst;
}

ConfigInfo* ParticleConfigFactory::create()
{
	ParticleConfig *particleCf	=	new ParticleConfig();
	return particleCf;
}