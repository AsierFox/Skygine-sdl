#include "Sprite.h"

Sprite::Sprite(std::string textureId, std::string resourcePath)
	: Sprite(textureId, resourcePath, 1)
{
}

Sprite::Sprite(std::string textureId, std::string resourcePath, float scale)
{
	TextureManager::getInstance()->load(textureId, resourcePath);

	this->m_textureId = textureId;

	int textureWidth = 0;
	int textureHeight = 0;
	TextureManager::getInstance()->queryWidthAndHeight(textureId, &textureWidth, &textureHeight);

	this->m_with = textureWidth;
	this->height = textureHeight;
	this->m_scale = scale;
}

Sprite::Sprite(std::string textureId, std::string resourcePath, int width, int height)
	: Sprite(textureId, resourcePath, width, height, 1)
{
}

Sprite::Sprite(std::string textureId, std::string resourcePath, int width, int height, float scale)
{
	TextureManager::getInstance()->load(textureId, resourcePath);

	this->m_textureId = textureId;
	this->m_with = width;
	this->height = height;
	this->m_scale = scale;
}

void Sprite::render(float x, float y)
{
	TextureManager::getInstance()->render(this->m_textureId, x, y, this->m_with, this->height, SDL_FLIP_NONE, this->m_scale, 1);
}

void Sprite::render(float x, float y, SDL_RendererFlip flip)
{
	TextureManager::getInstance()->render(this->m_textureId, x, y, this->m_with, this->height, flip, this->m_scale, 1);
}

void Sprite::render(float x, float y, SDL_RendererFlip flip, float moveWithCameraScalar)
{
	TextureManager::getInstance()->render(this->m_textureId, x, y, this->m_with, this->height, flip, this->m_scale, moveWithCameraScalar);
}

void Sprite::dispose()
{
	TextureManager::getInstance()->destroy(this->m_textureId);
}
