#include "TextureManager.h"

TextureManager* TextureManager::s_Instance = nullptr;

TextureManager* TextureManager::getInstance()
{
	if (nullptr == TextureManager::s_Instance)
	{
		s_Instance = new TextureManager();
	}

	return s_Instance;
}

TextureManager::TextureManager()
{
}

bool TextureManager::load(std::string id, std::string resourcePath)
{
	SDL_Surface* surface = IMG_Load(resourcePath.c_str());

	if (nullptr == surface)
	{
		spdlog::critical("[TextureManager.load] Cannot load surface from image '{0}': {1}", resourcePath, SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);

	if (nullptr == texture)
	{
		spdlog::critical("[TextureManager.load] Cannot load texture from surface '{0}': {1}", resourcePath, SDL_GetError());
		return false;
	}

	this->m_loadedTextures.insert({ id, texture });

	return true;
}

void TextureManager::render(std::string id, int x, int y, int width, int height)
{
	this->render(id, x, y, height, width, SDL_FLIP_NONE);
}

void TextureManager::render(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = {
		0, 0,
		width, height };

	SDL_Rect destRect = {
		x, y,
		width, height };

	SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), this->m_loadedTextures[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::queryWidthAndHeight(SDL_Texture* texture, int* width, int* height)
{
	SDL_QueryTexture(texture, nullptr, nullptr, width, height);
}

SDL_Texture* TextureManager::getTextureById(std::string id)
{
	return this->m_loadedTextures[id];
}

void TextureManager::destroy(std::string id)
{
	SDL_DestroyTexture(this->m_loadedTextures[id]);
	this->m_loadedTextures.erase(id);
}

void TextureManager::dispose()
{
	std::map<std::string, SDL_Texture*>::iterator it;

	for (it = this->m_loadedTextures.begin(); it != this->m_loadedTextures.end(); it++)
	{
		SDL_DestroyTexture(it->second);
	}
	
	this->m_loadedTextures.clear();
}
