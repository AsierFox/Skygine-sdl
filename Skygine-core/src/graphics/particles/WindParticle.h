#pragma once

#include <string>

#include "Particle.h"

class WindParticle : public Particle
{
public:

	static std::string s_textureId;
	static std::string s_resourcePath;

	WindParticle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime);
	WindParticle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime, bool isLoop);
};
