#include "ImagesConfigFactory.h"
#include "ImagesConfig.h"

ConfigInfoFactory* ImagesConfigFactory::inst = new ImagesConfigFactory();

ImagesConfigFactory::ImagesConfigFactory()
{
}

ImagesConfigFactory::~ImagesConfigFactory()
{
}

ConfigInfoFactory* ImagesConfigFactory::getInst()
{
	return inst;
}

ConfigInfo* ImagesConfigFactory::create()
{
	ImagesConfig *imageCf	=	new ImagesConfig();
	return imageCf;
}