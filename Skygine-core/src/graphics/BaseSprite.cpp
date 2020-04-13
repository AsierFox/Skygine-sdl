#include "BaseSprite.h"

BaseSprite::BaseSprite(std::string textureId, std::string resourcePath)
{
	TextureManager::getInstance()->load(textureId, resourcePath);

	this->m_textureId = textureId;
}

std::string BaseSprite::getTextureId()
{
	return this->m_textureId;
}

float BaseSprite::getFlip()
{
	return this->m_flip;
}
