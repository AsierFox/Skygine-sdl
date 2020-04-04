#pragma once

#include <map>
#include <spdlog/spdlog.h>
#include <SDL.h>
#include <SDL_image.h>

#include "Camera.h"
#include "../physics/Vector2D.h"
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
	void render(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip, float scale, float moveCameraWithDelay);
	void renderFrame(std::string id, int x, int y, int width, int height, int col, int row);
	void renderFrame(std::string id, int x, int y, int width, int height, int col, int row, SDL_RendererFlip flip);
	void renderFrame(std::string id, int x, int y, int width, int height, int col, int row, float scale);
	void renderFrame(std::string id, int x, int y, int width, int height, int col, int row, float scale, SDL_RendererFlip flip);
	void renderRect(SDL_Rect rect);
	void renderRect(float x, float y, float width, float height);
	void renderRect(float x, float y, float width, float height, float scale);
	void renderPoint(float x, float y);
	void queryWidthAndHeight(std::string id, int* width, int* height);
	SDL_Texture* getTextureById(std::string id);
	void destroy(std::string id);
	void dispose();
};
