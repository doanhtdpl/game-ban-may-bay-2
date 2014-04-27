#ifndef __MAP_CONTAINER_H_
#define __MAP_CONTAINER_H_

#include <string>
#include <vector>
#include "cocos2d.h"

class MapElement : public cocos2d::CCObject
{
public:
	double time;
	char* type;
	float fPositionX;
	float fPositionY;
};

class MapObject : public cocos2d::CCObject
{
public:
	MapObject();
	~MapObject();
	void addElement( MapElement *element );
	cocos2d::CCArray * getElement();
	
private:
	cocos2d::CCArray *elements;
};

class MapContainer
{
public:
	MapContainer();
	~MapContainer();

	bool readMap( char* pstrFileName );
	cocos2d::CCDictionary* getContainAt( double time );

protected:
private:
	cocos2d::CCDictionary *mapObjects;
};

#endif