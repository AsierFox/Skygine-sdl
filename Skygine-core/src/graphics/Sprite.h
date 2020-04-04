#pragma once

#include <SDL.h>

#include "TextureManager.h"

class Sprite
{
protected:

	std::string m_textureId;
	int m_with;
	int height;
	float m_scale;

	SDL_RendererFlip m_flip;

public:

	Sprite(std::string textureId, std::string resourcePath);
	Sprite(std::string textureId, std::string resourcePath, float scale);
	Sprite(std::string textureId, std::string resourcePath, int width, int height);
	Sprite(std::string textureId, std::string resourcePath, int width, int height, float scale);

	void render(float x, float y);
	void render(float x, float y, SDL_RendererFlip flip);
	void render(float x, float y, SDL_RendererFlip flip, float moveWithCameraScalar);
	void dispose();
};
