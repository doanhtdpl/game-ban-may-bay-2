#include "GameManager.h"
#include "GameObject.h"

GameManager::GameManager() : collisionManager()
{
	this->gojs	=	new cocos2d::CCArray(); 
}

GameManager::~GameManager()
{
	CC_SAFE_RELEASE( this->gojs );
	//CC_SAFE_DELETE( this->collisionManager );
}

bool GameManager::insert( GameObject *goj )
{
	if( this->gojs->containsObject( goj ) )
	{
		//OutputDebugString( L"Object already contain" );
		return false;
	}
	this->addChild( goj );
	this->gojs->addObject( goj );
	collisionManager.insert( goj );

	return true;
}

void GameManager::remove( GameObject *goj )
{
	if( this->gojs->containsObject( goj ) )
	{
		collisionManager.remove( goj );
		this->gojs->removeObject( goj );
		this->removeChild( goj );
	}
}

void GameManager::onUpdate( float deltaTime )
{
	for (unsigned i = 0; i < this->gojs->count(); ++i )
	{
		GameObject *goj =	(GameObject *) this->gojs->objectAtIndex( i );
	}

	collisionManager.onUpdate( deltaTime );
}