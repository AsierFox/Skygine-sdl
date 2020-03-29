#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int width, int height)
	: SpriteAnimation(textureId, resourcePath, width, height, 1)
{
}

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int width, int height, float scale)
{
	TextureManager::getInstance()->load(textureId, resourcePath);

	this->m_textureId = textureId;
	this->m_currentRow = 0;
	this->m_currentFrame = 0;
	this->m_totalFrames = 2;
	this->m_scale = scale;

	this->m_width = width;
	this->m_height = height;

	this->m_delay = 150;
}

void SpriteAnimation::update()
{
	this->m_currentFrame = (SDL_GetTicks() / this->m_delay) % this->m_totalFrames;

	spdlog::debug("SpriteAnimation::update currentFrame: {}", SDL_GetTicks());
}

void SpriteAnimation::render(float x, float y)
{
	TextureManager::getInstance()->renderFrame(this->m_textureId, x, y, this->m_width, this->m_height, this->m_currentRow, this->m_currentFrame, this->m_scale);
}

void SpriteAnimation::dispose()
{
	TextureManager::getInstance()->destroy(this->m_textureId);
}
