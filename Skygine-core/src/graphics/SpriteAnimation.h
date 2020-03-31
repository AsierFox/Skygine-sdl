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
	int m_totalRows;
	float m_scale;
	int m_delay;
	int m_currentFrame;

public:

	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int rows, int cols);
	SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int rows, int cols, float scale);

	void update();
	void render(float x, float y);
	void dispose();
};
