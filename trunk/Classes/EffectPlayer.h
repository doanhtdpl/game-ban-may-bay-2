#ifndef __EFFECT_PLAYER_H_
#define __EFFECT_PLAYER_H_

#include "cocos2d.h"

class EffectPlayer : public cocos2d::CCNode
{
public:
	~EffectPlayer();

	void playEffect( char* type, cocos2d::CCPoint pos );
	cocos2d::CCSprite *playEffect( char* type );

	static EffectPlayer* getInst();

	void endEffect( void* sender );
protected:

private:
	EffectPlayer();
		
	cocos2d::CCArray	arr;
	cocos2d::CCArray	arrAction;

	static EffectPlayer *inst;
};

#endif