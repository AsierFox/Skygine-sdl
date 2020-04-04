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

bool CollisionHandler::checkMapCollision(SDL_Rect a)
{
	// TODO The collision handler can have the map (?)
	// And here, I can do the checking of neighbour tile,
	// adding currentTile position as parameter of this funcion
	return false;
}
