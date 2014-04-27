#ifndef __GAME_PLAYER_H_
#define __GAME_PLAYER_H_

#include "GameCharacter.h"

class GamePlayer : public GameCharacter
{
public:
	GamePlayer();
	~GamePlayer();

	// write for mobile game so touch event is used
	virtual void inputProcess(  cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent  );
protected:
private:

};

#endif // __GAME_PLAYER_H_