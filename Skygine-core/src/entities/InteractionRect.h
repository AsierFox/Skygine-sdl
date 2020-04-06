#pragma once

#include <SDL.h>

class InteractionRect
{
	SDL_Rect rect;

public:

	void update();
	void draw();
};
 