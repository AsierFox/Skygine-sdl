#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <SDL.h>

#include "IRenderable.h"
#include "TextureManager.h"

class SpriteSheetRegion
{
	std::string m_textureId;

	int m_col;
	int m_row;
	int m_frameWidth;
	int m_frameHeight;
	int m_totalCols;
	int m_totalRows;
	float m_scale;

	SDL_RendererFlip m_flip;

public:

	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows);
	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale);
	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale, SDL_RendererFlip flip);

	void render(float x, float y);
	void dispose();

	float getWidth();
	float getHeight();
};
