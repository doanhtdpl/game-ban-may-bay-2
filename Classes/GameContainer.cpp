#include "GameContainer.h"

GameContainer::GameContainer() : cocos2d::CCNode()
{

}

GameContainer::~GameContainer()
{

}

void GameContainer::addChild( cocos2d::CCNode *sprite )
{
	cocos2d::CCNode::addChild( sprite );
}

void GameContainer::removeChild( cocos2d::CCNode *sprite )
{
	cocos2d::CCNode::removeChild( sprite );
}