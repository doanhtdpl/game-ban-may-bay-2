#ifndef __CONFIG_INFO_FACTORY_H_
#define __CONFIG_INFO_FACTORY_H_

class ConfigInfo;
class ConfigInfoFactory
{
public:
	virtual ConfigInfo *create() = 0;
};

#endif