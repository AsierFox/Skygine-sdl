#pragma once

#include <spdlog/spdlog.h>

struct Vector2D
{
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	void log();

	Vector2D operator+(const Vector2D& other) const;
	Vector2D operator-(const Vector2D& other) const;
	Vector2D operator*(const float scalar) const;
	bool operator==(const Vector2D& other) const;

	// Calculates the magnitude
	float length();
};
