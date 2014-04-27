#include "ImagesConfig.h"


ImagesConfig::ImagesConfig()
{
}

ImagesConfig::~ImagesConfig()
{
}

bool ImagesConfig::insert( std::string bucket, std::string component )
{
	if( strcmp( bucket.c_str(), "ID" ) == 0 )
	{
		id		=	new char[component.length()+1];
		strcpy( id, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "FileName" ) == 0 )
	{
		fileName=	new char[component.length()+1];
		strcpy( fileName, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "HasBullet" ) == 0 )
	{
		hasBullet	=	strcmp( component.c_str(), "TRUE" ) == 0 ? true : false;
	}
	else if( strcmp( bucket.c_str(), "ScaleX" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fScaleX		=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "ScaleY" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fScaleY		=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "Rotation" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fRotation	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "Number" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		numberBullet=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "PositionX1" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		positionX1	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "PositionY1" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		positionY1	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "PositionX2" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		positionX2	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "PositionY2" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		positionY2	=	str->floatValue();
	}
	return true;
}