#include "AirPlaneConfig.h"
#include "cocos2d.h"

AirPlaneConfig::AirPlaneConfig()
{
}

AirPlaneConfig::~AirPlaneConfig()
{
}

bool AirPlaneConfig::insert( std::string bucket, std::string component )
{
	if( strcmp( bucket.c_str(), "ID" ) == 0 )
	{
		id			=	new char[component.length()+1];
		strcpy( id, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Hp" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		hp			=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "Damage" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		damage		=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "HasBullet" ) == 0 )
	{
		hasBullet	=	strcmp( component.c_str(), "TRUE" ) == 0 ? true : false;
	}
	else if( strcmp( bucket.c_str(), "Image" ) == 0 )
	{
		image		=	new char[component.length()+1];
		strcpy( image, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Velocity" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fVelocity	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "BulletType" ) == 0 )
	{
		bulletType	=	new char[component.length()+1];
		strcpy( bulletType, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Direction" ) == 0 )
	{
		iDirection	=	atoi(component.c_str());
	}
	return true;
}