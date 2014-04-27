#include "Config.h"
#include "ConfigInfo.h"
#include "ConfigInfoFactory.h"
#include "stringUtilities.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Config* Config::inst = NULL;

Config::Config()
{
	configDatas	=	cocos2d::CCDictionary::create();
	configDatas->retain();
}

Config::~Config()
{
	if( configDatas != NULL )
	{
		configDatas->removeAllObjects();
		configDatas->release();
	}
}

Config* Config::getInst()
{
	if( inst == NULL )
	{
		inst	=	new Config();
	}
	return inst;
}

ConfigObj* Config::getMetadata( char* dataName )
{
	return (ConfigObj*)configDatas->objectForKey( dataName );
}

bool Config::loadCSVConfig( char* fileName, ConfigInfoFactory *infoFactory )
{
 	ifstream file;
	std::string fullPath	=	CCFileUtils::sharedFileUtils()->fullPathForFilename( fileName );

	unsigned long size = 0;
	char* pBuffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &size);
	std::stringstream ss(pBuffer);

	string value;

	bool firstLine	=	true;
	vector<string> infoTitle;

	ConfigObj *row	=	new ConfigObj();

	while ( getline ( ss, value ) )
	{
		if( value.length() != 0 )
		{
			vector<string> result = StringUtilities::split( value, ',' );
			vector<string>::iterator it	=	result.begin();
			if( !firstLine )
			{
				vector<string>::iterator iit	=	infoTitle.begin();
				ConfigInfo *configInfo	=	infoFactory->create();
				for ( ; it != result.end() && iit != infoTitle.end(); ++it, ++iit )
				{
					configInfo->insert( *iit, *it );
				}
				string id	=	*result.begin();
				row->getDict()->setObject( configInfo , id );
			}
			else
			{
				firstLine	=	false;
				infoTitle	=	result;
			}
		}
	}
	configDatas->setObject( row, fileName );

	file.close();

	return true;
}