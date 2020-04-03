#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "IRenderable.h"
#include "TextureManager.h"

class SpriteAnimation
{
	std::string m_textureId;

	int m_frameWidth;
	int m_frameHeight;
	int m_currentRow;
	int m_totalFrames;
	int m_totalCols;
	int m_totalRows;
	float m_scale;
	int m_delay;
	int m_currentFrame;

	SDL_RendererFlip m_flip;

public:

	// TODO Refactor cols & rows to totalCols & totalRows
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int cols, int rows);
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int cols, int rows, float scale);
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int cols, int rows, float scale, SDL_RendererFlip flip);

	void update();
	void render(float x, float y);
	void dispose();

	float getWidth();
	float getHeight();
};
