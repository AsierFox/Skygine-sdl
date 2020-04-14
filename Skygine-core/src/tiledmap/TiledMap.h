#pragma once

#include <vector>

#include <SDL.h>

#include "TileLayer.h"
#include "ObjectLayer.h"

class TiledMap
{
	int m_tileSize;
	int m_totalCols;
	int m_totalRows;
	int m_totalTileLayers;
	float m_scale;

	std::vector<TileLayer*> m_tileLayers;
	ObjectLayer* m_objectLayer;

public:

	TiledMap(int tileSize, int totalCols, int totalRows, std::vector<TileLayer*> tileLayers, ObjectLayer* objectLayer);
	TiledMap(int tileSize, int totalCols, int totalRows, std::vector<TileLayer*> tileLayers, ObjectLayer* objectLayer, float scale);

	void update();
	void render();

	void dispose();

	int getTileSize();
	int getTotalCols();
	int getTotalRows();
	float getScale();
	int getTotalWidth();
	int getTotalHeight();
	std::vector<SDL_Rect> getColliders();
};
