#pragma once

#include <spdlog/spdlog.h>

struct Point
{
	float x;
	float y;

	Point();
	Point(float x, float y);

	void log();

	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point operator*(const float scalar) const;
};
