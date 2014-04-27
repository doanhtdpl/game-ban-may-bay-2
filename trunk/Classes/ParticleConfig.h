#ifndef __PARTICLE_CONFIG_H_
#define __PARTICLE_CONFIG_H_

#include "ConfigInfo.h"

class ParticleConfig : public ConfigInfo
{
public:
	ParticleConfig();
	~ParticleConfig();

	bool insert( std::string bucket, std::string component );

	char* id;
	char *image;
	int from;
	int to;
private:

};

#endif