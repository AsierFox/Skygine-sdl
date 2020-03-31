#include "LayerTile.h"

LayerTile::LayerTile(int tileSize, int totalCols, int totalRows, std::vector<std::vector<int>> tileMapIds, std::vector<Tileset> tilesets)
{
	this->m_tileSize = tileSize;
	this->m_totalCols = totalCols;
	this->m_totalRows = totalRows;
	this->m_tileMapIds = tileMapIds;
	this->m_tilesets = tilesets;
}

void LayerTile::update()
{
}

void LayerTile::render()
{
}
