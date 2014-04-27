#ifndef __CONFIG_OBJ_H_
#define __CONFIG_OBJ_H_

#include "cocos2d.h"

class ConfigObj : public cocos2d::CCObject
{
public:
	ConfigObj();
	~ConfigObj();

	cocos2d::CCDictionary *getDict();

private:
	cocos2d::CCDictionary *dict;

};

#endif