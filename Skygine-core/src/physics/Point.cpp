#include "Point.h"

Point::Point()
	: x(0), y(0)
{
}

Point::Point(float x, float y)
	: x(x), y(y)
{
}

void Point::log()
{
	spdlog::debug("[Point::log] x ({0}) y ({1})", this->x, this->y);
}

Point Point::operator+(const Point& other) const
{
	return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(const Point& other) const
{
	return Point(this->x - other.x, this->y - other.y);
}

Point Point::operator*(const float scalar) const
{
	return Point(this->x * scalar, this->y * scalar);
}
