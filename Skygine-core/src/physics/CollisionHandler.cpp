#include "CollisionHandler.h"

CollisionHandler* CollisionHandler::m_instance = nullptr;

CollisionHandler::CollisionHandler()
{
}

CollisionHandler* CollisionHandler::getInstance()
{
	if (nullptr == CollisionHandler::m_instance)
	{
		CollisionHandler::m_instance = new CollisionHandler;
	}

	return CollisionHandler::m_instance;
}

bool CollisionHandler::checkCollision(SDL_Rect a, SDL_Rect b)
{
	return a.x + a.w > b.x && b.x + b.w > a.x
		&& a.y + a.h > b.y && b.y + b.h > a.y;
}

Direction CollisionHandler::getRectDepthSideCollision(SDL_Rect a, SDL_Rect b)
{
	int dx = (a.x + (a.w >> 1)) - (b.x + (b.w >> 1));
	int dy = (a.y + (a.h >> 1)) - (b.y + (b.h >> 1));
	int width = (a.w + b.w) >> 1;
	int height = (a.h + b.h) >> 1;
	int crossWidth = width * dy;
	int crossHeight = height * dx;

	if (crossWidth > crossHeight) {
		if (crossWidth > -crossHeight) {
			return Direction::UP;
		}
		else {
			return Direction::RIGHT;
		}
	}
	else {
		if (crossWidth > -crossHeight) {
			return Direction::LEFT;
		}
		else {
			return Direction::DOWN;
		}
	}
}
