#ifndef __IMAGES_CONFIG_FACTORY_H_
#define __IMAGES_CONFIG_FACTORY_H_

#include "ConfigInfoFactory.h"

class ImagesConfigFactory : public ConfigInfoFactory
{
public:
	~ImagesConfigFactory();
	static ConfigInfoFactory* getInst();

	ConfigInfo *create();

private:
	ImagesConfigFactory();
	static ConfigInfoFactory* inst;
};

#endif