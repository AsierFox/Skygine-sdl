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
	if (this->isAlreadyLoaded(id))
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

	spdlog::debug("[TextureManager::load] Texture '{0}' loaded successfully!", resourcePath);

	this->m_loadedTextures.insert({ id, texture });

	return texture;
}

void TextureManager::render(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight)
{
	this->render(id, x, y, frameWidth, frameHeight, scaledWidth, scaledHeight, SDL_FLIP_NONE, 1);
}

void TextureManager::render(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, SDL_RendererFlip flip, float moveCameraWithScalar)
{
	Vector2D cam = Camera::getInstance()->getPosition() * moveCameraWithScalar;

	SDL_Rect srcRect = {
		0, 0,
		frameWidth, frameHeight };

	SDL_Rect destRect = {
		x - cam.x, y - cam.y,
		scaledWidth, scaledHeight };

	SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), this->m_loadedTextures[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::renderFrame(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, int col, int row)
{
	this->renderFrame(id, x, y, frameWidth, frameHeight, scaledWidth, scaledHeight, col, row, SDL_FLIP_NONE);
}

void TextureManager::renderFrame(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, int col, int row, SDL_RendererFlip flip)
{
	Vector2D cam = Camera::getInstance()->getPosition();

	SDL_Rect srcRect = {
		col * frameWidth, row * frameHeight,
		frameWidth, frameHeight };

	SDL_Rect destRect = {
		x - cam.x, y - cam.y,
		scaledWidth, scaledHeight };

	if (x + scaledWidth > Camera::getInstance()->getViewport().x
		&& y + scaledHeight > Camera::getInstance()->getViewport().y
		&& x < (Camera::getInstance()->getViewport().x + Camera::getInstance()->getViewport().w)
		&& y < (Camera::getInstance()->getViewport().y + Camera::getInstance()->getViewport().h))
	{
		SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), this->m_loadedTextures[id], &srcRect, &destRect, 0, nullptr, flip);
	}
}

void TextureManager::renderRect(SDL_Rect rect)
{
	this->renderRect(rect.x, rect.y, rect.w, rect.h, SDLUtils::getSDLColor(255, 0, 0, 255));
}

void TextureManager::renderRect(float x, float y, float width, float height)
{
	this->renderRect(x, y, width, height, SDLUtils::getSDLColor(255, 0, 0, 255));
}

void TextureManager::renderRect(float x, float y, float width, float height, SDL_Color color)
{
	Vector2D cam = Camera::getInstance()->getPosition();

	SDL_Rect rect = {
		x - cam.x, y - cam.y,
		width, height };

	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(Engine::getInstance()->getRenderer(), &rect);
}

void TextureManager::renderPoint(float x, float y)
{
	Vector2D cam = Camera::getInstance()->getPosition();

	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), 255, 255, 255, 255);
	SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), x - cam.x, y - cam.y);
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

bool TextureManager::isAlreadyLoaded(std::string id)
{
	return this->m_loadedTextures.count(id) > 0;
}
