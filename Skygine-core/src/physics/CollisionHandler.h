#pragma once

#include <vector>
#include <SDL.h>
#include <spdlog/spdlog.h>

class CollisionHandler
{
	static CollisionHandler* m_instance;

	CollisionHandler();

public:

	static CollisionHandler*  getInstance();

	bool checkCollision(SDL_Rect a, SDL_Rect b);
	bool checkMapCollision(SDL_Rect a);
};
