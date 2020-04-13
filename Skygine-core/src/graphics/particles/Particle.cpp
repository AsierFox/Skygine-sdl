#include "Particle.h"

Particle::Particle(BaseSprite* sprite, Transform originPosition, Vector2D velocity, Uint32 lifeTime, bool isLoop)
{
	this->m_sprite = sprite;
	this->m_pos = originPosition;
	this->m_velocity = velocity;
	this->m_lifeTime = SDL_GetTicks() + lifeTime;
	this->m_isLoop = isLoop;

	this->m_isDead = false;
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

bool Particle::isLoop()
{
	return this->m_isLoop;
}

bool Particle::isDead()
{
	return this->m_isDead;
}

void Particle::isDead(bool isDead)
{
	this->m_isDead = isDead;
}

BaseSprite* Particle::getSprite()
{
	return this->m_sprite;
}

void Particle::setTransform(Transform newPosition)
{
	this->m_pos = newPosition;
}

void Particle::setLifeTime(Uint32 newLifeTime)
{
	this->m_lifeTime = SDL_GetTicks() + newLifeTime;
}
