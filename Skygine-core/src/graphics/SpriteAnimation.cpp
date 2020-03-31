#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int rows, int cols)
	: SpriteAnimation(textureId, resourcePath, rowToAnimate, rows, cols, 1)
{
}

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int rows, int cols, float scale)
{
	TextureManager::getInstance()->load(textureId, resourcePath);

	this->m_textureId = textureId;
	this->m_currentRow = rowToAnimate;
	this->m_totalFrames = cols;
	this->m_totalRows = rows;
	this->m_scale = scale;

	int textureWidth = 0;
	int textureHeight = 0;
	TextureManager::getInstance()->queryWidthAndHeight(textureId, &textureWidth, &textureHeight);
	
	this->m_frameWidth = textureWidth / this->m_totalFrames;
	this->m_frameHeight = textureHeight  / this->m_totalRows;

	this->m_delay = 350;
	this->m_currentFrame = 0;
}

void SpriteAnimation::update()
{
	this->m_currentFrame = (SDL_GetTicks() / this->m_delay) % this->m_totalFrames;
}

void SpriteAnimation::render(float x, float y)
{
	TextureManager::getInstance()->renderFrame(this->m_textureId, x, y, this->m_frameWidth, this->m_frameHeight, this->m_currentRow, this->m_currentFrame, this->m_scale);
}

void SpriteAnimation::dispose()
{
	TextureManager::getInstance()->destroy(this->m_textureId);
}
