#include "RigitBody.h"

RigitBody::RigitBody()
{
	this->m_gravity = GRAVITY;
	this->m_mass = DEFAULT_MASS;
}

void RigitBody::update(float delta)
{
	// Force + Friction = Mass * Acceleration
	this->m_acceleration.x = (this->m_force.x + this->m_friction.x) / this->m_mass;
	this->m_acceleration.y = (this->m_force.y + this->m_friction.y) / this->m_mass;

	this->m_velocity = this->m_acceleration * delta;

	this->m_newPosition = this->m_velocity * delta;
}

void RigitBody::updateWithGravity(float delta)
{
	// Force + Friction = Mass * Acceleration
	this->m_acceleration.x = (this->m_force.x + this->m_friction.x) / this->m_mass;
	// acceleration * mass = gravity * mass + force (drag)
	this->m_acceleration.y = this->m_gravity + this->m_force.y / m_mass;

	this->m_velocity = this->m_acceleration * delta;

	this->m_newPosition = this->m_velocity * delta;
}

void RigitBody::setGravity(float gravity)
{
	this->m_gravity = gravity;
}

float RigitBody::getMass()
{
	return this->m_mass;
}

void RigitBody::setMass(float mass)
{
	this->m_mass = mass;
}

Vector2D RigitBody::getAcceleration()
{
	return this->m_acceleration;
}

Vector2D RigitBody::getVelocity()
{
	return this->m_velocity;
}

Vector2D RigitBody::getNewPosition()
{
	return this->m_newPosition;
}

Vector2D RigitBody::getForce()
{
	return this->m_force;
}

void RigitBody::setForce(Vector2D force)
{
	this->m_force = force;
}

void RigitBody::setForceX(float x)
{
	this->m_force.x = x;
}

void RigitBody::setForceY(float y)
{
	this->m_force.y = y;
}

void RigitBody::removeForce()
{
	this->m_force = Vector2D(0, 0);
}

void RigitBody::setFriction(Vector2D friction)
{
	this->m_friction = friction;
}

void RigitBody::removeFriction()
{
	this->m_friction = Vector2D(0, 0);
}
