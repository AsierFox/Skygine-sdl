#include "Particle.h"

Particle::Particle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime)
{
	this->m_isDead = false;
	this->m_pos = originPosition;
	this->m_velocity = velocity;
	this->m_lifeTime = SDL_GetTicks() + lifeTime;
	this->m_sprite = sprite;
}

void Particle::update(float dt)
{
	this->m_pos.x += this->m_velocity.x * dt;
	this->m_pos.y += this->m_velocity.y * dt;

	this->m_lifeTime -= dt;

	if (SDL_GetTicks() >= this->m_lifeTime)
	{
		this->m_isDead = true;
	}
}

void Particle::render()
{
	this->m_sprite->render(this->m_pos.x, this->m_pos.y);
}

bool Particle::isDead()
{
	return this->m_isDead;
}
