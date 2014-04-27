#ifndef __GAME_CONTAINER_H_
#define __GAME_CONTAINER_H_

#include "cocos2d.h"

class GameContainer : public cocos2d::CCNode
{
public:
	GameContainer();
	~GameContainer();

	void addChild( cocos2d::CCNode *sprite );

	void removeChild( cocos2d::CCNode *sprite );

private:
};

#endif