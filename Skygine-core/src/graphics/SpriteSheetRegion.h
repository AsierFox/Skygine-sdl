#pragma once

#include "BaseSprite.h"

class SpriteSheetRegion : public BaseSprite
{
	int m_col;
	int m_row;
	int m_frameWidth;
	int m_frameHeight;
	int m_totalCols;
	int m_totalRows;

public:

	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows);
	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale);
	SpriteSheetRegion(std::string textureId, std::string resourcePath, int col, int row, int totalCols, int totalRows, float scale, SDL_RendererFlip flip);

	void render(float x, float y) override;
	void dispose() override;
	float getWidth() override;
	float getHeight() override;
};
