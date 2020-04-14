#pragma once

#include <SDL.h>

#include "../types/Direction.h"

class CollisionHandler
{
	static CollisionHandler* m_instance;

	CollisionHandler();

public:

	static CollisionHandler*  getInstance();

	bool checkCollision(SDL_Rect a, SDL_Rect b);
	Direction getRectDepthSideCollision(SDL_Rect a, SDL_Rect b);
};
