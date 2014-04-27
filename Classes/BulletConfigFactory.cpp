#include "BulletConfigFactory.h"
#include "BulletConfig.h"

ConfigInfoFactory *BulletConfigFactory::inst = new BulletConfigFactory();

BulletConfigFactory::BulletConfigFactory()
{
}

BulletConfigFactory::~BulletConfigFactory()
{
}

ConfigInfoFactory* BulletConfigFactory::getInst()
{
	return inst;
}

ConfigInfo* BulletConfigFactory::create()
{
	BulletConfig *bulletCf	=	new BulletConfig();
	return bulletCf;
}