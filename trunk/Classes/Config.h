#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <map>
#include <vector>
#include "ConfigObj.h"
#include "cocos2d.h"

using namespace std;

class ConfigInfo;
class ConfigInfoFactory;

class Config
{
public:
	~Config();

	static Config *getInst();

	ConfigObj* getMetadata( char* dataName );
	bool loadCSVConfig( char* fileName, ConfigInfoFactory *infoFactory );

protected:

private:
	Config();

private:
	cocos2d::CCDictionary *configDatas;
	static Config *inst;
};

#endif