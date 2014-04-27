#ifndef __COLLISION_UTILITIES_H_
#define __COLLISION_UTILITIES_H_

#include "cocos2d.h"

class CollisionUtilities
{
public:
	static bool isIntersect( cocos2d::CCRect rect1, cocos2d::CCRect rect2 );

private:
	CollisionUtilities();
};

#endif // __COLLISION_UTILITIES_H_