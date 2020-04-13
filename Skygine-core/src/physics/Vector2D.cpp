#include "Vector2D.h"

Vector2D::Vector2D()
	: x(0), y(0)
{
}

Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{
}

void Vector2D::log()
{
	spdlog::debug("[Vector2D::log] x ({0}) y ({1})", this->x, this->y);
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
	return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
	return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(const float scalar) const
{
	return Vector2D(this->x * scalar, this->y * scalar);
}

bool Vector2D::operator==(const Vector2D& other) const
{
	return this->x == other.x && this->y == other.y;
}

float Vector2D::length()
{
	return fabsf(sqrtf(this->x * this->x) + (this->y * this->y));
}
