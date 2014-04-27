#include "AirPlaneConfigFactory.h"
#include "AirPlaneConfig.h"

ConfigInfoFactory* AirPlaneConfigFactory::inst = new AirPlaneConfigFactory();

AirPlaneConfigFactory::AirPlaneConfigFactory()
{
}

AirPlaneConfigFactory::~AirPlaneConfigFactory()
{
}

ConfigInfoFactory* AirPlaneConfigFactory::getInst()
{
	return inst;
}

ConfigInfo* AirPlaneConfigFactory::create()
{
	AirPlaneConfig *enemyCf	=	new AirPlaneConfig();
	return enemyCf;
}