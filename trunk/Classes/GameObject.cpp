#include "GameObject.h"

GameObject::GameObject() :cocos2d::CCNode(), body(NULL)
{ 
	isDead	=	false;
	collisionList	=	cocos2d::CCArray::create();
	collisionList->retain();
}

GameObject::~GameObject()
{
	collisionList->release();
}

cocos2d::CCRect GameObject::getBound()
{
	if( this->body != NULL )
	{
		cocos2d::CCRect bodySize	=	body->boundingBox();
		cocos2d::CCPoint bodyPoint	=	this->getPosition();
		cocos2d::CCRect bound		=	cocos2d::CCRectMake( bodyPoint.x - bodySize.size.width/2, 
			bodyPoint.y - bodySize.size.height/2, bodySize.size.width, bodySize.size.height );
		return bound;
	}
	return cocos2d::CCRectMake(0, 0, 0, 0);
}

bool GameObject::isCollideWith( GameObject *goj )
{
	return false;
}

void GameObject::saveCollideWith( GameObject *goj )
{
}

void GameObject::applyCollision()
{
}

bool GameObject::isAlive()
{
	return !isDead;
}

void GameObject::registerCollisionObject()
{
	collisionList	=	new cocos2d::CCArray();
}