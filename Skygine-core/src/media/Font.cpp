#include "Font.h"

Font::Font(std::string resourcePath, std::string message, int size)
	: Font(resourcePath, message, size, { 255, 255, 255 })
{
}

Font::Font(std::string resourcePath, std::string message, int size, SDL_Color color)
{
	this->m_fontTrueType = TTF_OpenFont(resourcePath.c_str(), size);

	if (!this->m_fontTrueType)
	{
		throw TTF_GetError();
	}

	this->m_message = message;
	this->m_color = color;
	this->m_fontSurface = TTF_RenderText_Solid(this->m_fontTrueType, this->m_message.c_str(), color);
	this->m_fontTexture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), this->m_fontSurface);
	this->m_fontRect= {
		0, 0,
		this->m_fontSurface->w, this->m_fontSurface->h };
}

void Font::renderFont(int x, int y)
{
	this->m_fontRect.x = x;
	this->m_fontRect.y = y;
	SDL_RenderCopy(Engine::getInstance()->getRenderer(), this->m_fontTexture, NULL, &this->m_fontRect);
}

void Font::dispose()
{
	SDL_DestroyTexture(this->m_fontTexture);
	SDL_FreeSurface(this->m_fontSurface);
	TTF_CloseFont(this->m_fontTrueType);
}
