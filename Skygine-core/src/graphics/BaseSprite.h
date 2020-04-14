#pragma once

#include <string>

#include <SDL.h>

#include "TextureManager.h"

class BaseSprite
{
	std::string m_textureId;

protected:

	float m_scale;

	SDL_RendererFlip m_flip;

public:

	BaseSprite(std::string textureId, std::string resourcePath);

	virtual void render(float x, float y) = 0;
	virtual void dispose() = 0;
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;

	std::string getTextureId();
	float getFlip();
};
