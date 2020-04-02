#pragma once

#include <vector>

#include "Layer.h"

class TiledMap
{
	int m_tileSize;
	int m_totalCols;
	int m_totalRows;
	int m_totalLayers;

	std::vector<Layer*> m_layers;

public:

	TiledMap(int tileSize, int totalCols, int totalRows, std::vector<Layer*> layers);

	void update();
	void render();

	void dispose();
};
