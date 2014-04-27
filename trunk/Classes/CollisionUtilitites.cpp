#include "CollisionUtiliies.h"

bool CollisionUtilities::isIntersect( cocos2d::CCRect rect1, cocos2d::CCRect rect2 )
{
	return rect1.intersectsRect( rect2 );
}