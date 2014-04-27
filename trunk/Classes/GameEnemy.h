#ifndef __GAME_ENEMY_H_
#define __GAME_ENEMY_H_

#include "GameCharacter.h"

class GamePlayer;

class GameEnemy : public GameCharacter
{
public:
	GameEnemy();
	GameEnemy( float fx, float fy, int iHp );
	~GameEnemy();

	// Free ai
	virtual void aiProcess( void );
	// Ai make with game player like chasing / path finding...
	virtual void aiProcess( GamePlayer *player );
	// Ai make with another enemy like make a group
	virtual void aiProcess( GameEnemy *enemy );
	// Ai make with any game character
	virtual void aiProcess( GameCharacter *character );
	// Ai make with any game obj, that can be a tree, cloud...
	virtual void aiProcess( GameObject *goj );

	// Count number of enemy
	static int GameEnemyCounter;

protected:
private:
};

#endif // __GAME_ENEMY_H_