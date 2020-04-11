#pragma once

#include <SDL.h>

#include "BaseSprite.h"
#include "TextureManager.h"

class Sprite : public BaseSprite
{
	int m_width;
	int height;
	float m_scale;

	SDL_RendererFlip m_flip;

public:

	Sprite(std::string textureId, std::string resourcePath);
	Sprite(std::string textureId, std::string resourcePath, float scale);
	Sprite(std::string textureId, std::string resourcePath, int width, int height);
	Sprite(std::string textureId, std::string resourcePath, int width, int height, float scale);

	void render(float x, float y) override;
	void render(float x, float y, SDL_RendererFlip flip);
	void render(float x, float y, SDL_RendererFlip flip, float moveWithCameraScalar);
	void dispose() override;
	float getWidth() override;
	float getHeight() override;
};
