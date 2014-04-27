#include "BulletConfig.h"

BulletConfig::BulletConfig()
{
}

BulletConfig::~BulletConfig()
{
}

bool BulletConfig::insert( std::string bucket, std::string component )
{
	if( strcmp( bucket.c_str(), "ID" ) == 0 )
	{
		cptrId			=	new char[component.length()+1];
		strcpy( cptrId, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Damage" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fDamage		=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "Image" ) == 0 )
	{
		cptrImage		=	new char[component.length()+1];
		strcpy( cptrImage, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "Velocity" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		fVelocity	=	str->floatValue();
	}
	else if( strcmp( bucket.c_str(), "EffectType" ) == 0 )
	{
		effectType		=	new char[component.length()+1];
		strcpy( effectType, component.c_str() );
	}
	return true;
}