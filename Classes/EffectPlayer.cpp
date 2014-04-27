#include "EffectPlayer.h"
#include "Config.h"
#include "ConfigObj.h"
#include "Constant.h"
#include "ImagesConfig.h"
#include "ParticleConfig.h"

USING_NS_CC;

EffectPlayer *EffectPlayer::inst	=	new EffectPlayer();

EffectPlayer::EffectPlayer()
{
}

EffectPlayer::~EffectPlayer()
{
}

EffectPlayer* EffectPlayer::getInst()
{
	return inst;
}

void  EffectPlayer::playEffect( char* type, cocos2d::CCPoint pos )
{
	ConfigObj *particleConfigs		=	Config::getInst()->getMetadata( STR_PARTICLE );
	ParticleConfig *particleConf	=	(ParticleConfig*)(particleConfigs->getDict()->objectForKey(type));

	ConfigObj *imgConfigs			=	Config::getInst()->getMetadata( STR_IMAGES );
	ImagesConfig *imgConf	=	(ImagesConfig*)( imgConfigs->getDict()->objectForKey( particleConf->image ));

	CCArray *effArr = new CCArray();
	CCSprite *spr;
	if( particleConf->from == particleConf->to )
	{
		char name[32]			=	{0};
		char currentResult[100]	=	{0};
		strcpy( currentResult, imgConf->fileName );
		strcat( currentResult, ".png" );
		spr = CCSprite::createWithSpriteFrameName( currentResult );
		effArr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(currentResult));
	}
	else 
	{
		for(int i = particleConf->from; i <= particleConf->to; i++)
		{
			char name[32]			=	{0};
			char currentResult[100]	=	{0};
			strcpy( currentResult, imgConf->fileName );
			sprintf(name, "%d.png", i);
			strcat( currentResult, name );

			if( i == particleConf->from )
				spr = CCSprite::createWithSpriteFrameName( currentResult );

			effArr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(currentResult));
		}
	}
	
	if( spr != NULL )
	{
		CCAnimation *anim			=	CCAnimation::createWithSpriteFrames( effArr, 0.1f );
		CCAnimate	*animate		=	CCAnimate::create( anim );
		CCCallFuncN *callstartGame	=	CCCallFuncN::create( this, callfuncN_selector(EffectPlayer::endEffect) );

		addChild( spr );
		spr->runAction( CCSequence::create( animate, callstartGame, NULL ) );
		spr->setPosition( pos );
	}
}

cocos2d::CCSprite* EffectPlayer::playEffect( char* type )
{
	ConfigObj *particleConfigs		=	Config::getInst()->getMetadata( STR_PARTICLE );
	ParticleConfig *particleConf=	(ParticleConfig*)( particleConfigs->getDict()->objectForKey( type ));

	ConfigObj *imgConfigs		=	Config::getInst()->getMetadata( STR_IMAGES );
	ImagesConfig *imgConf	=	(ImagesConfig*)( imgConfigs->getDict()->objectForKey( particleConf->image ));

 	CCArray *effArr =	new CCArray();
	CCSprite *spr	=	NULL;
	if( particleConf->from == particleConf->to )
	{
		char name[32]			=	{0};
		char currentResult[100]	=	{0};
		strcpy( currentResult, imgConf->fileName );
		strcat( currentResult, ".png" );
		spr = CCSprite::createWithSpriteFrameName( currentResult );
		effArr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(currentResult));
	}
	else 
	{
		for(int i = particleConf->from; i <= particleConf->to; i++)
		{
			char name[32]			=	{0};
			char currentResult[100]	=	{0};
			strcpy( currentResult, imgConf->fileName );
			sprintf(name, "%d.png", i);
			strcat( currentResult, name );

			if( i == particleConf->from )
				spr = CCSprite::createWithSpriteFrameName( currentResult );

			effArr->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(currentResult));
		}
	}

	if( spr != NULL )
	{
		CCAnimation *anim			=	CCAnimation::createWithSpriteFrames( effArr, 0.1f );
		CCAnimate	*animate		=	CCAnimate::create( anim );
		CCCallFuncN *callstartGame	=	CCCallFuncN::create( this, callfuncN_selector(EffectPlayer::endEffect) );

		spr->runAction( CCSequence::create( animate, callstartGame, NULL ) );
	}

	return spr;
}

void EffectPlayer::endEffect( void* sender )
{
	try
	{
		CCSprite *spr	=	(CCSprite*) sender;
		spr->removeFromParent();
	}
	catch (...)
	{
	}
}