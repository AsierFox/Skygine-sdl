#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "IRenderable.h"
#include "TextureManager.h"

class SpriteAnimation
{
	std::string m_textureId;

	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_totalFrames;
	int m_delay;
	float m_scale;

public:

	SpriteAnimation(std::string textureId, std::string resourcePath, int width, int height);
	SpriteAnimation(std::string textureId, std::string resourcePath, int width, int height, float scale);

	void update();
	void render(float x, float y);
	void dispose();
};
