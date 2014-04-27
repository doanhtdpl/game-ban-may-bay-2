#ifndef __CONFIG_INFO_H_
#define __CONFIG_INFO_H_

#include <string>
#include "cocos2d.h"

USING_NS_CC;

class ConfigInfo : public CCObject
{
public:
	virtual bool insert( std::string bucket, std::string component )	=	0;
};

#endif