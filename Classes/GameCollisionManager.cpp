#include "GameCollisionManager.h"
#include "GameObject.h"
#include "CollisionUtiliies.h"

GameCollisionManager::GameCollisionManager()
{
	this->gojs	=	new cocos2d::CCArray();
}

GameCollisionManager::~GameCollisionManager()
{
	CC_SAFE_RELEASE( gojs );
}

bool GameCollisionManager::insert( GameObject *goj )
{
	if( this->gojs->containsObject( goj ) )
	{
		return false;
	}

	this->gojs->addObject( goj );
	return true;
}

void GameCollisionManager::remove( GameObject *goj )
{
	if( this->gojs->containsObject( goj ) )
	{
		this->gojs->removeObject( goj );
	}
}

void GameCollisionManager::onUpdate( float deltaTime )
{
	// Call to check collision
	onCheckCollision( deltaTime );

	// Call to apply collision
	onApplyCollision( deltaTime );

	// Call to remove result collision
	onRemoveDead( deltaTime );
}

void GameCollisionManager::onCheckCollision( float deltaTime )
{
	unsigned count	=	gojs->count();
	for ( unsigned i = 0; count != 0 && i < (count - 1); ++i )
	{
		for ( unsigned j = i+1; j < count; ++j )
		{
			GameObject *gojA	=	(GameObject*)(gojs->objectAtIndex( i ));
			GameObject *gojB	=	(GameObject*)(gojs->objectAtIndex( j ));
			if( gojA->getBound().intersectsRect( gojB->getBound() ) )
			{
				if(gojA->isCollideWith( gojB ))
					gojA->saveCollideWith( gojB);

				if( gojB->isCollideWith( gojA ))
					gojB->saveCollideWith( gojA);
			}
		}
	}
}

void GameCollisionManager::onApplyCollision( float deltaTime )
{
	for( unsigned i = 0; i < this->gojs->count(); ++i )
	{
		GameObject *obj	=	(GameObject *) this->gojs->objectAtIndex( i );
		obj->applyCollision();
	}
}

void GameCollisionManager::onRemoveDead( float deltaTime )
{
	int count			=	this->gojs->count();
	for ( unsigned i = 0; i < count; ++i )
	{
		GameObject *goj	=	(GameObject*)(gojs->objectAtIndex( i ));
		if( !goj->isAlive() )
		{
			gojs->removeObjectAtIndex(i);
			goj->removeFromParent();
			goj->release();
			--i;
			// re-calculate obj counter
			count	=	gojs->count();
		}
	}
}