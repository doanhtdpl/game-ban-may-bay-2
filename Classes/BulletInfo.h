#ifndef __BULLET_INFO_H_
#define __BULLET_INFO_H_

struct BulletInfo 
{
	// The velocity movement of air craft enemy
	// The bigger velocity the faster air craft
	float fVelocity;
	// Image for air craft
	char* cptrImage;
	// Type of bullet
	// If air craft can not fire, type is 0
	char* iBulletType;
	// Effect type
	char *effectType;
	// Hp
	float fDamage;
	// Original position
	float fx;
	float fy;
	// Scale image
	float fScaleX;
	float fScaleY;
	// Rotation image
	float fRotation;

	BulletInfo( float fVelocity, char* cptrImage, char* iBulletType, float fDamage, float fx, float fy, 
		float fScaleX, float fScaleY, float fRotation, char* effectType )
	{
		this->fVelocity		=	fVelocity;
		this->cptrImage		=	cptrImage;
		this->iBulletType	=	iBulletType;
		this->fDamage		=	fDamage;
		this->fx			=	fx;
		this->fy			=	fy;
		this->fScaleX		=	fScaleX;
		this->fScaleY		=	fScaleY;
		this->fRotation		=	fRotation;
		this->effectType	=	effectType;
	}
};

#endif