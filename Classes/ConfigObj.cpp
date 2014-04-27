#include "ConfigObj.h"

ConfigObj::ConfigObj()
{
	dict	=	cocos2d::CCDictionary::create();
	dict->retain();
}

ConfigObj::~ConfigObj()
{
	if( dict )
	{
		dict->removeAllObjects();
		dict->release();
	}
}

cocos2d::CCDictionary *ConfigObj::getDict()
{
	return this->dict;
}