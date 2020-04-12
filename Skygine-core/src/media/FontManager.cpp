#include "FontManager.h"

FontManager* FontManager::s_instance = nullptr;

FontManager::FontManager()
{
}

FontManager* FontManager::getInstance()
{
	if (nullptr == FontManager::s_instance)
	{
		FontManager::s_instance = new FontManager;
	}

	return FontManager::s_instance;
}

void FontManager::loadFont(std::string id, std::string resourcePath, std::string message, int fontSize)
{
	SDL_Color defaultColor = { 255, 255, 255 };
	this->loadFont(id, resourcePath, message, fontSize, defaultColor);
}

void FontManager::loadFont(std::string id, std::string resourcePath, std::string message, int fontSize, SDL_Color fontColor)
{
	try {
		Font* font = new Font(resourcePath, message, fontSize, fontColor);

		this->m_loadedFonts.insert({ id, font });

		spdlog::debug("[FontManager::loadFont] Font with id '{0}' loaded successfully!", id);
	}
	catch(const char* errorMessage)
	{
		spdlog::debug("[FontManager::loadFont] Failed to load font width id '{0}' in path '{1}'!: {2}", id, resourcePath, errorMessage);
	}
}

void FontManager::renderFont(std::string id, int x, int y)
{
	this->m_loadedFonts[id]->renderFont(x, y);
}

void FontManager::disposeFont(std::string id)
{
	this->m_loadedFonts[id]->dispose();
	this->m_loadedFonts.erase(id);
}

void FontManager::dispose()
{
	std::map<std::string, Font*>::iterator it;
	
	for (it = this->m_loadedFonts.begin(); it != this->m_loadedFonts.end(); it++)
	{
		this->disposeFont(it->first);
	}
	this->m_loadedFonts.clear();
}
