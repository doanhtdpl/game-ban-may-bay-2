#include "GameCharacter.h"

GameCharacter::GameCharacter() : GameObject(), velocity( 0.f, 0.f )
{
	this->hp		=	0;
}

GameCharacter::GameCharacter( float fx, float fy, int iHp ) : GameObject()
{
	this->velocity	=	ccp( fx, fy );
	this->hp		=	iHp;
}

GameCharacter::~GameCharacter()
{
}

cocos2d::CCPoint& GameCharacter::getVelocity()
{
	return velocity;
}

void GameCharacter::setVelocity( float fx, float fy )
{
	this->velocity.x	=	fx;
	this->velocity.y	=	fy;
}

void GameCharacter::setHP( int _hp )
{
	this->hp			=	_hp;
}

int GameCharacter::getHP()
{
	return this->hp;
}

void GameCharacter::setDamage( float damage )
{
	this->damage	=	damage;
}

float GameCharacter::getDamage()
{
	return damage;
}