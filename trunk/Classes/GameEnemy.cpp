#include "GameEnemy.h"
#include "GamePlayer.h"

int GameEnemy::GameEnemyCounter	=	0;

GameEnemy::GameEnemy() : GameCharacter()
{
	++GameEnemy::GameEnemyCounter;
}

GameEnemy::GameEnemy( float fx, float fy, int iHp ) : GameCharacter( fx, fy, iHp )
{
	++GameEnemy::GameEnemyCounter;
}

GameEnemy::~GameEnemy()
{
	--GameEnemy::GameEnemyCounter;
}

void GameEnemy::aiProcess( void )
{
}

void GameEnemy::aiProcess( GamePlayer *player )
{
}

void GameEnemy::aiProcess( GameEnemy *enemy )
{
}

void GameEnemy::aiProcess( GameCharacter *character )
{
}

void GameEnemy::aiProcess( GameObject *goj )
{
}