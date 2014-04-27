#ifndef __IMAGES_CONFIG_H_
#define __IMAGES_CONFIG_H_

#include "ConfigInfo.h"

class ImagesConfig : public ConfigInfo
{
public:
	ImagesConfig();
	~ImagesConfig();

	bool insert( std::string bucket, std::string component );

	char* id;
	char* fileName;
	bool hasBullet;
	float fScaleX;
	float fScaleY;
	float fRotation;
	int numberBullet;
	float positionX1;
	float positionY1;
	float positionX2;
	float positionY2;
private:

};

#endif