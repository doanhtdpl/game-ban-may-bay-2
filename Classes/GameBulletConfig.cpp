#include "GameBulletConfig.h"
#include "stringUtilities.h"

GameBulletConfig::GameBulletConfig()
{
}

GameBulletConfig::~GameBulletConfig()
{
}

bool GameBulletConfig::insert( std::string bucket, std::string component )
{
	if( strcmp( bucket.c_str(), "ID" ) == 0 )
	{
		strType			=	new char[component.length()+1];
		strcpy( strType, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Number" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		number		=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "Child" ) == 0 )
	{
		std::vector<std::string> subs	=	StringUtilities::split( component, ':' );
		std::vector<std::string>::iterator ite	=	subs.begin();
		for ( ; ite != subs.end(); ++ite )
		{
			childs.push_back( *ite );
		}
	}
	else if( strcmp( bucket.c_str(), "PosX" ) == 0 )
	{
		std::vector<std::string> subs	=	StringUtilities::split( component, ':' );
		std::vector<std::string>::iterator ite	=	subs.begin();
		for ( ; ite != subs.end(); ++ite )
		{
			std::string s = *ite;
			posxs.push_back( atof(s.c_str()) );
		}
	}
	else if( strcmp( bucket.c_str(), "PosY" ) == 0 )
	{
		std::vector<std::string> subs	=	StringUtilities::split( component, ':' );
		std::vector<std::string>::iterator ite	=	subs.begin();
		for ( ; ite != subs.end(); ++ite )
		{
			std::string s = *ite;
			cocos2d::CCString *str	=	cocos2d::CCString::create(s);
			posys.push_back( str->floatValue() );
		}
	}
	else if( strcmp( bucket.c_str(), "Time" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fTime	=	 str->floatValue();
	}
	return true;
}