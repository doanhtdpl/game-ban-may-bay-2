#include "GameBulletConfigFactory.h"
#include "GameBulletConfig.h"

ConfigInfoFactory* GameBulletConfigFactory::inst = new GameBulletConfigFactory();

GameBulletConfigFactory::GameBulletConfigFactory()
{
}

GameBulletConfigFactory::~GameBulletConfigFactory()
{
}

ConfigInfoFactory* GameBulletConfigFactory::getInst()
{
	return inst;
}

ConfigInfo* GameBulletConfigFactory::create()
{
	GameBulletConfig *gameBulletCf	=	new GameBulletConfig();
	return gameBulletCf;
}