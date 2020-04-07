#pragma once

#include "Vector2D.h"

//#define GRAVITY 9.81f
#define GRAVITY 2.8f
#define DEFAULT_MASS 1.0f

class RigitBody  
{
	float m_gravity;
	float m_mass;

	Vector2D m_acceleration;
	Vector2D m_velocity;
	Vector2D m_newPosition;
	Vector2D m_force;
	Vector2D m_friction;

public:

	RigitBody();

	void update(float delta);
	void updateWithGravity(float delta);

	void setGravity(float gravity);
	float getMass();
	void setMass(float mass);
	Vector2D getAcceleration();
	Vector2D getVelocity();
	Vector2D getNewPosition();
	Vector2D getForce();
	void setForce(Vector2D force);
	void setForceX(float x);
	void setForceY(float y);
	void removeForce();
	void setFriction(Vector2D friction);
	void removeFriction();
};
