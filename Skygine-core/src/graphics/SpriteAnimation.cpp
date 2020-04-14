#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows)
	: SpriteAnimation(textureId, resourcePath, rowToAnimate, totalFrames, totalCols, totalRows, 1, SDL_FLIP_NONE)
{
}

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows, float scale)
	: SpriteAnimation(textureId, resourcePath, rowToAnimate, totalFrames, totalCols, totalRows, scale, SDL_FLIP_NONE)
{
}

SpriteAnimation::SpriteAnimation(std::string textureId, std::string resourcePath, int rowToAnimate, int totalFrames, int totalCols, int totalRows, float scale, SDL_RendererFlip flip)
	: BaseSprite(textureId, resourcePath)
{
	// Subtract 1 to be the first row 1 for contructor
	this->m_currentRow = rowToAnimate - 1;
	this->m_totalFrames = totalFrames;
	this->m_totalCols = totalCols;
	this->m_totalRows = totalRows;
	this->m_scale = scale;

	int textureWidth = 0;
	int textureHeight = 0;
	TextureManager::getInstance()->queryWidthAndHeight(textureId, &textureWidth, &textureHeight);

	this->m_frameWidth = textureWidth / this->m_totalCols;
	this->m_frameHeight = textureHeight  / this->m_totalRows;

	this->m_flip = flip;

	this->m_delay = 350;
	this->m_repeat = true;
	this->m_currentFrame = 0;
}

void SpriteAnimation::update()
{
	this->m_currentFrame = (SDL_GetTicks() / this->m_delay) % this->m_totalFrames;
}

void SpriteAnimation::render(float x, float y)
{
	TextureManager::getInstance()->renderFrame(this->getTextureId(), x, y, this->m_frameWidth, this->m_frameHeight, this->getWidth(), this->getHeight(), this->m_currentFrame, this->m_currentRow, this->m_flip);
}

void SpriteAnimation::dispose()
{
	TextureManager::getInstance()->destroy(this->getTextureId());
}

float SpriteAnimation::getWidth()
{
	return this->m_frameWidth * this->m_scale;
}

float SpriteAnimation::getHeight()
{
	return this->m_frameHeight * this->m_scale;
}
