#pragma once

#include <map>
#include <spdlog/spdlog.h>
#include <SDL.h>
#include <SDL_image.h>

#include "../core/Engine.h"

class TextureManager
{
	static TextureManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_loadedTextures;

	TextureManager();

public:

	static TextureManager* getInstance();

	SDL_Texture* load(std::string id, std::string resourcePath);
	void render(std::string id, int x, int y, int width, int height);
	void render(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip);
	void renderFrame(std::string id, int x, int y, int width, int height, int row, int col);
	void renderFrame(std::string id, int x, int y, int width, int height, int row, int col, SDL_RendererFlip flip);
	void renderFrame(std::string id, int x, int y, int width, int height, int row, int col, float scale);
	void renderFrame(std::string id, int x, int y, int width, int height, int row, int col, float scale, SDL_RendererFlip flip);
	void queryWidthAndHeight(std::string id, int* width, int* height);
	SDL_Texture* getTextureById(std::string id);
	void destroy(std::string id);
	void dispose();
};
