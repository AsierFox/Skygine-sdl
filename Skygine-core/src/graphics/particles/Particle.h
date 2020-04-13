#pragma once

#include <SDL.h>

#include "../../physics/Transform.h"
#include "ParticleType.h"
#include "../BaseSprite.h"
#include "../TextureManager.h"

class Particle
{
	bool m_isDead;
	Transform m_pos;
	Vector2D m_velocity;
	Uint32 m_lifeTime;
	BaseSprite* m_sprite;

public:

	Particle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime);

	virtual void update(float dt);
	virtual void render();
	bool isDead();
	// TODO Think about how to dispose a shared SpriteSheet used by all particles (Maybe in SpriteSpawner?)
	//virtual void dispose() = 0;
};
