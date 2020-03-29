#pragma once

#include <spdlog/spdlog.h>

#include "Vector2D.h"

struct Transform
{
	float x;
	float y;

	Transform(float x, float y);

	void translateX(float x);
	void translateY(float y);
	void translateVector2D(Vector2D vector2D);
	void log();
};
