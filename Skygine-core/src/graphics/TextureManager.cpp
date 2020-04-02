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

SDL_Texture* TextureManager::load(std::string id, std::string resourcePath)
{
	// TODO Create method isAlreadyLoaded()
	if (this->m_loadedTextures.count(id) > 0)
	{
		spdlog::debug("[TextureManager::load] The texture with id '{0}' already exists in the map", id);
		return this->getTextureById(id);
	}

	SDL_Surface* surface = IMG_Load(resourcePath.c_str());

	if (nullptr == surface)
	{
		// TODO Throw exceptions
		spdlog::critical("[TextureManager::load] Cannot load surface from image '{0}': {1}", resourcePath, SDL_GetError());
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);

	if (nullptr == texture)
	{
		spdlog::critical("[TextureManager::load] Cannot load texture from surface '{0}': {1}", resourcePath, SDL_GetError());
		return nullptr;
	}

	spdlog::debug("[TextureManager::load] Texture '{0}' loaded!", resourcePath);

	this->m_loadedTextures.insert({ id, texture });

	return texture;
}

void TextureManager::render(std::string id, int x, int y, int width, int height)
{
	this->render(id, x, y, height, width, SDL_FLIP_NONE);
}

void TextureManager::render(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	this->renderFrame(id, x, y, width, height, 0, 0, 1, flip);
}

void TextureManager::renderFrame(std::string id, int x, int y, int width, int height, int col, int row)
{
	this->renderFrame(id, x, y, width, height, col, row, 1, SDL_FLIP_NONE);
}

void TextureManager::renderFrame(std::string id, int x, int y, int width, int height, int col, int row, SDL_RendererFlip flip)
{
	this->renderFrame(id, x, y, width, height, col, row, 1, SDL_FLIP_NONE);
}

void TextureManager::renderFrame(std::string id, int x, int y, int width, int height, int col, int row, float scale)
{
	this->renderFrame(id, x, y, width, height, col, row, scale, SDL_FLIP_NONE);
}

void TextureManager::renderFrame(std::string id, int x, int y, int width, int height, int col, int row, float scale, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = {
		col * width, row * height,
		width, height };

	SDL_Rect destRect = {
		x, y,
		width * scale, height * scale };

	SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), this->m_loadedTextures[id], &srcRect, &destRect, 0, nullptr, flip);

	// TODO Refactor debug border to another method
	/*SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), 255, 0, 0, 255);
	SDL_RenderDrawRect(Engine::getInstance()->getRenderer(), &destRect);*/
}

void TextureManager::queryWidthAndHeight(std::string id, int* width, int* height)
{
	SDL_QueryTexture(getTextureById(id), nullptr, nullptr, width, height);
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
