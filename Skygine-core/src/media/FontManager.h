#pragma once

#include <map>
#include <string>

#include "Font.h"

class FontManager
{
	static FontManager* s_instance;
	
	std::map<std::string, Font*> m_loadedFonts;

	FontManager();

public:

	static FontManager* getInstance();

	void loadFont(std::string id, std::string resourcePath, std::string message, int fontSize);
	void loadFont(std::string id, std::string resourcePath, std::string message, int fontSize, SDL_Color fontColor);
	void renderFont(std::string id, int x, int y);
	void disposeFont(std::string id);
	void dispose();
};
