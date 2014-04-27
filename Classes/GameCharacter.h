#ifndef __GAME_CHARACTER_H_
#define __GAME_CHARACTER_H_

#include "GameObject.h"

class GameCharacter : public GameObject
{
public:
	GameCharacter();
	GameCharacter( float fx, float fy, int iHp );
	virtual ~GameCharacter();

	cocos2d::CCPoint& getVelocity();
	void setVelocity( float fx, float fy );

	void setHP( int _hp );
	int getHP();

	void setDamage( float damage );
	float getDamage();

protected:
	float damage;
	int	hp;
	cocos2d::CCPoint	velocity;
private:
};

#endif // __GAME_CHARACTER_H_