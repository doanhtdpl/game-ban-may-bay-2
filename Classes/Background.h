#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_

#include "cocos2d.h"

class Background : public cocos2d::CCNode
{
public:
	Background( char* fileName );
	~Background();

	void update( float delta );

private:
	// it's preventing
	Background();

	float fCenterX;
	float fCenterY, fdbCenterY;

	float fVx, fVy;

	cocos2d::CCSprite *inst1;
	cocos2d::CCSprite *inst2;
};

#endif