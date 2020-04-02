#include "TiledMap.h"

TiledMap::TiledMap(int tileSize, int totalCols, int totalRows, std::vector<Layer*> layers)
{
	this->m_tileSize    = tileSize;
	this->m_totalCols   = totalCols;
	this->m_totalRows   = totalRows;
	this->m_layers      = layers;
	this->m_totalLayers = layers.size();
}

void TiledMap::update()
{
	for (unsigned int i = 0; i < this->m_totalLayers; i++)
	{
		this->m_layers[i]->update();
	}
}

void TiledMap::render()
{
	for (unsigned int i = 0; i < this->m_totalLayers; i++)
	{
		this->m_layers[i]->render();
	}
}

void TiledMap::dispose()
{
	for (unsigned int i = 0; i < this->m_totalLayers; i++)
	{
		// TODO implement method
	}
}
