#pragma once

#include <string>
#include <SDL_ttf.h>

#include "../core/Engine.h"

class Font
{
	std::string m_message;

	TTF_Font* m_fontTrueType;
	SDL_Color m_color;
	SDL_Surface* m_fontSurface;
	SDL_Texture* m_fontTexture;
	SDL_Rect m_fontRect;

public:

	Font(std::string resourcePath, std::string message, int size);
	Font(std::string resourcePath, std::string message, int size, SDL_Color color);

	void renderFont(int x, int y);
	// TODO Create setMessage function to change the message
	void dispose();
};
