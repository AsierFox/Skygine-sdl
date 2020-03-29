#include "Sprite.h"

Sprite::Sprite(std::string textureId, int width, int height)
	: Sprite(textureId, width, height, 1)
{
}

Sprite::Sprite(std::string textureId, int width, int height, float scale)
{
	this->m_textureId = textureId;
	this->m_with = width;
	this->height = height;
	this->m_scale = scale;
}
