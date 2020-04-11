#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <SDL.h>

#include "BaseSprite.h"
#include "TextureManager.h"

class SpriteAnimation : public BaseSprite
{
	int m_frameWidth;
	int m_frameHeight;
	int m_currentRow;
	int m_totalFrames;
	int m_totalCols;
	int m_totalRows;
	float m_scale;
	int m_delay;
	int m_currentFrame;
	bool m_repeat;

	SDL_RendererFlip m_flip;

public:

	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows);
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows, float scale);
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows, float scale, SDL_RendererFlip flip);

	void update();
	void render(float x, float y) override;
	void dispose() override;
	float getWidth() override;
	float getHeight() override;
};
