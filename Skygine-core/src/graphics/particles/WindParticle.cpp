#include "WindParticle.h"

std::string WindParticle::s_textureId = "wind-particle";
std::string WindParticle::s_resourcePath = "assets/particles/particles-sheet.png";

WindParticle::WindParticle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime)
	: Particle(sprite, originPosition, velocity, lifeTime, false)
{
}

WindParticle::WindParticle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime, bool isLoop)
	: Particle(sprite, originPosition, velocity, lifeTime, isLoop)
{
}
