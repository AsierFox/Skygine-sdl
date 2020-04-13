#pragma once

#include <SDL.h>

#include "../../physics/Transform.h"
#include "ParticleType.h"
#include "../BaseSprite.h"
#include "../TextureManager.h"

class Particle
{
	bool m_isLoop;
	bool m_isDead;
	BaseSprite* m_sprite;
	Transform m_pos;
	Vector2D m_velocity;
	Uint32 m_lifeTime;

public:

	Particle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime, bool isLoop);

	virtual void update(float dt);
	virtual void render();

	bool isLoop();
	bool isDead();
	void isDead(bool isDead);
	BaseSprite* getSprite();
	void setTransform(Transform newPosition);
	void setLifeTime(Uint32 newLifeTime);
	// TODO Think about how to dispose a shared SpriteSheet used by all particles (Maybe in SpriteSpawner?)
	//virtual void dispose() = 0;
};
