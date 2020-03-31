#pragma once

#include <string>
#include <vector>

#include "Layer.h"
#include "Tileset.h"

class LayerTile : Layer
{
	int m_tileSize;
	int m_totalCols;
	int m_totalRows;

	std::vector<std::vector<int> > m_tileMapIds;
	std::vector<Tileset> m_tilesets;

public:

	LayerTile(int tileSize, int totalCols, int totalRows, std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets);

	virtual void update() override;
	virtual void render() override;
};
