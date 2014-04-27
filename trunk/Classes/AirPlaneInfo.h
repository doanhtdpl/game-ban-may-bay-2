#ifndef __AIR_PLANE_INFO_H_
#define __AIR_PLANE_INFO_H_

struct AirPlaneInfo 
{
	// The velocity movement of air craft enemy
	// The bigger velocity the faster air craft
	float fVelocity;
	// Air type represent for the size of air craft
	// 1 - smallest and gradually
	int iAirType;
	// Image for air craft
	char* cptrImage;
	// Type of bullet
	// If air craft can not fire, type is 0
	int iBulletType;
	// Hp
	int iHp;
	// Original position
	float fx;
	float fy;

	AirPlaneInfo( float fVelocity, int iAirType, char* cptrImage, int iBulletType, int iHp, float fx, float fy )
	{
		this->fVelocity		=	fVelocity;
		this->iAirType		=	iAirType;
		this->cptrImage		=	cptrImage;
		this->iBulletType	=	iBulletType;
		this->iHp			=	iHp;
		this->fx			=	fx;
		this->fy			=	fy;
	}
};

#endif