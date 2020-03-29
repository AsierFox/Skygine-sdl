#pragma once

#include <SDL.h>

#include "../physics/Transform.h"

class Sprite
{
protected:

	std::string m_textureId;
	int m_with;
	int height;
	float m_scale;

	SDL_RendererFlip m_flip;

public:

	Sprite(std::string textureId, int width, int height);
	Sprite(std::string textureId, int width, int height, float scale);
};
