#pragma once

#include "BaseSprite.h"

class Sprite : public BaseSprite
{
	int m_width;
	int m_height;
	float m_scale;

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
