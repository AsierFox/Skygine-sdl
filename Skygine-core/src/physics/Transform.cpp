#include "Transform.h"

Transform::Transform(float x, float y)
	: x(x), y(y)
{
}

void Transform::translateX(float x)
{
	this->x += x;
}

void Transform::translateY(float y)
{
	this->y += y;
}

void Transform::translateVector2D(Vector2D vector2D)
{
	this->x += vector2D.x;
	this->y += vector2D.y;
}

void Transform::log()
{
	spdlog::debug("[Transform::log] Transform x ({0}) y ({1})", this->x, this->y);
}
