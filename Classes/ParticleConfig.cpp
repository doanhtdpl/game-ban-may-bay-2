#include "ParticleConfig.h"

ParticleConfig::ParticleConfig()
{
}

ParticleConfig::~ParticleConfig()
{
}

bool ParticleConfig::insert( std::string bucket, std::string component )
{
	if( strcmp( bucket.c_str(), "ID" ) == 0 )
	{
		id			=	new char[component.length()+1];
		strcpy( id, component.c_str() );
	}
	else if( strcmp( bucket.c_str(), "From" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		from		=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "To" ) == 0 )
	{
		cocos2d::CCString *str	=	cocos2d::CCString::create(component);
		to			=	str->intValue();
	}
	else if( strcmp( bucket.c_str(), "Image" ) == 0 )
	{
		image		=	new char[component.length()+1];
		strcpy( image, component.c_str() );
	}
	return true;
}