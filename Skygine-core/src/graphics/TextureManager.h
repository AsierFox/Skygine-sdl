#pragma once

#include <map>
#include <string>

#include <SDL_image.h>
#include <spdlog/spdlog.h>

#include "../core/Engine.h"
#include "../physics/Vector2D.h"
#include "Camera.h"
#include "../utils/SDLUtils.h"

class TextureManager
{
	static TextureManager* s_Instance;

	std::map<std::string, SDL_Texture*> m_loadedTextures;

	TextureManager();

public:

	static TextureManager* getInstance();

	SDL_Texture* load(std::string id, std::string resourcePath);
	void render(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight);
	void render(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, SDL_RendererFlip flip, float moveCameraWithScalar);
	void renderFixed(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, SDL_RendererFlip flip, float moveCameraWithScalar);
	void renderFrame(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, int col, int row);
	void renderFrame(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, int col, int row, SDL_RendererFlip flip);
	void renderFrameFixed(std::string id, int x, int y, int frameWidth, int frameHeight, int scaledWidth, int scaledHeight, int col, int row, SDL_RendererFlip flip);
	void renderRect(SDL_Rect rect);
	void renderRect(float x, float y, float width, float height);
	void renderRect(float x, float y, float width, float height, SDL_Color color);
	void renderPoint(float x, float y);
	void queryWidthAndHeight(std::string id, int* width, int* height);
	SDL_Texture* getTextureById(std::string id);
	void destroy(std::string id);
	void dispose();

private:

	bool isAlreadyLoaded(std::string id);
};
