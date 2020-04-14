#pragma once

#include "Vector2D.h"

struct Transform
{
	float x;
	float y;

	Transform();
	Transform(float x, float y);

	Transform operator+(const Vector2D& other) const;
	Transform operator-(const Vector2D& other) const;
	void translateX(float x);
	void translateY(float y);
	void translateVector2D(Vector2D vector2D);
	void log();
};
