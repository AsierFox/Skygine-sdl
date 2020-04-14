#include "Sprite.h"

Sprite::Sprite(std::string textureId, std::string resourcePath)
	: Sprite(textureId, resourcePath, 1)
{
}

Sprite::Sprite(std::string textureId, std::string resourcePath, float scale)
	: BaseSprite(textureId, resourcePath)
{
	int textureWidth = 0;
	int textureHeight = 0;
	TextureManager::getInstance()->queryWidthAndHeight(textureId, &textureWidth, &textureHeight);

	this->m_width = textureWidth;
	this->m_height = textureHeight;
	this->m_scale = scale;
}

Sprite::Sprite(std::string textureId, std::string resourcePath, int width, int height)
	: Sprite(textureId, resourcePath, width, height, 1)
{
}

Sprite::Sprite(std::string textureId, std::string resourcePath, int width, int height, float scale)
	: BaseSprite(textureId, resourcePath)
{
	this->m_width = width;
	this->m_height = height;
	this->m_scale = scale;
}

void Sprite::render(float x, float y)
{
	TextureManager::getInstance()->render(this->getTextureId(), x, y, this->m_width, this->m_height, this->getWidth(), this->getHeight(), SDL_FLIP_NONE, 1);
}

void Sprite::render(float x, float y, SDL_RendererFlip flip)
{
	TextureManager::getInstance()->render(this->getTextureId(), x, y, this->m_width, this->m_height, this->getWidth(), this->getHeight(), flip, 1);
}

void Sprite::render(float x, float y, SDL_RendererFlip flip, float moveWithCameraScalar)
{
	TextureManager::getInstance()->render(this->getTextureId(), x, y, this->m_width, this->m_height, this->getWidth(), this->getHeight(), flip, moveWithCameraScalar);
}

void Sprite::dispose()
{
	TextureManager::getInstance()->destroy(this->getTextureId());
}

float Sprite::getWidth()
{
	return this->m_width * this->m_scale;
}

float Sprite::getHeight()
{
	return this->m_height * this->m_scale;
}
