#include "MapContainer.h"
#include "stringUtilities.h"

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

MapObject::MapObject()
{
	elements	=	cocos2d::CCArray::create();
	elements->retain();
}

MapObject::~MapObject()
{
	if( elements != NULL ) 
		elements->release();
}

void MapObject::addElement( MapElement *element )
{
	elements->addObject( element );
}

cocos2d::CCArray *MapObject::getElement()
{
	return elements;
}

MapContainer::MapContainer()
{
	mapObjects	=	cocos2d::CCDictionary::create();
	mapObjects->retain();
}

MapContainer::~MapContainer()
{
	mapObjects->removeAllObjects();
	mapObjects->release();
}

bool comparer(MapObject i, MapObject j) 
{ 
	return ( i.time < j.time );
}

bool MapContainer::readMap( char* pstrFileName )
{
	ifstream file ( pstrFileName );
	string value;
	bool firstLine	=	true;
	vector<string> infoTitle;
	while ( file.good() )
	{
		getline ( file, value );
		if( value.length() != 0 )
		{
			vector<string> result = StringUtilities::split( value, ',');
			vector<string>::iterator iit	=	result.begin();

			if( !firstLine )
			{
				MapElement *mapElement	=	new MapElement();
				vector<string>::iterator it	=	infoTitle.begin();
				for ( ; iit != result.end() && it != infoTitle.end(); ++it, ++iit )
				{
					if( strcmp( (*it).c_str(), "STT" ) == 0 )
					{
					}
					else if( strcmp( (*it).c_str(), "Time" ) == 0 )
					{
						std::string s	=	(*iit);
						mapElement->time	=	(float)atof(s.c_str());
					}
					else if( strcmp( (*it).c_str(), "Type" ) == 0 )
					{
						mapElement->type	=	new char[(*iit).length()+1];
						strcpy( mapElement->type, (*iit).c_str() );
					}
					else if( strcmp( (*it).c_str(), "PosX" ) == 0 )	
					{
						std::string s	=	(*iit);
						mapElement->fPositionX	=	(float)atof(s.c_str());
					}
					else if( strcmp( (*it).c_str(), "PosY" ) == 0 )
					{
						std::string s	=	(*iit);
						mapElement->fPositionY	=	(float)atof(s.c_str());
					}
				}
				cocos2d::CCObject * object	=	mapObjects->objectForKey( mapElement->time );
				if( mapObjects->objectForKey( mapElement->time ) != NULL )
				{
					MapObject *mapObject	=	(MapObject*)object;
					mapObject->addElement( mapElement );
				}
				else
				{
					MapObject *mapObject	=	new MapObject();
					mapObject->addElement( mapElement );
					mapObjects->setObject( mapObject, mapElement->time );
				}
			}
			else
			{
				firstLine	=	false;
				infoTitle	=	result;
			}
		}
	}

// 	if( mapObjects->count() > 0 )
// 		mapObjects->s
// 		std::sort( mapObjects.begin(), mapObjects.end(), comparer );

	file.close();

	return true;
}

cocos2d::CCDictionary* MapContainer::getContainAt( double time )
{
	cocos2d::CCDictionary *objs	=	cocos2d::CCDictionary::create();

	mapObjects->objectForKey( time );

	return objs;
}