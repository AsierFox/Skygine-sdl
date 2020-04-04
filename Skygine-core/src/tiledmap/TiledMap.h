#pragma once

#include <iostream>
#include <vector>

#include "TileLayer.h"
#include "ObjectLayer.h"

class TiledMap
{
	int m_tileSize;
	int m_totalCols;
	int m_totalRows;
	int m_totalTileLayers;

	std::vector<TileLayer*> m_tileLayers;
	ObjectLayer* m_objectLayer;

public:

	TiledMap(int tileSize, int totalCols, int totalRows, std::vector<TileLayer*> tileLayers, ObjectLayer* objectLayer);

	void update();
	void render();

	void dispose();

	int getTileSize();
	int getTotalCols();
	int getTotalRows();
	std::vector<SDL_Rect> getColliders();
};
