#include "TiledMap.h"

TiledMap::TiledMap(int tileSize, int totalCols, int totalRows, std::vector<TileLayer*> tileLayers, ObjectLayer* objectLayer)
	: TiledMap(tileSize, totalCols, totalRows, tileLayers, objectLayer, 1)
{
}

TiledMap::TiledMap(int tileSize, int totalCols, int totalRows, std::vector<TileLayer*> tileLayers, ObjectLayer* objectLayer, float scale)
{
	this->m_tileSize = tileSize;
	this->m_totalCols = totalCols;
	this->m_totalRows = totalRows;
	this->m_tileLayers = tileLayers;
	this->m_totalTileLayers = tileLayers.size();
	this->m_objectLayer = objectLayer;
	this->m_scale = scale;
}

void TiledMap::update()
{
	this->m_objectLayer->update();

	for (unsigned int i = 0; i < this->m_totalTileLayers; i++)
	{
		this->m_tileLayers[i]->update();
	}
}

void TiledMap::render()
{
	for (unsigned int i = 0; i < this->m_totalTileLayers; i++)
	{
		this->m_tileLayers[i]->render();
	}

	this->m_objectLayer->render();
}

void TiledMap::dispose()
{
	while (!this->m_tileLayers.empty())
	{
		delete this->m_tileLayers.back(), this->m_tileLayers.pop_back();
	}
	
	delete this->m_objectLayer;
}

int TiledMap::getTileSize()
{
	return this->m_tileSize * this->getScale();
}

int TiledMap::getTotalCols()
{
	return this->m_totalCols;
}

int TiledMap::getTotalRows()
{
	return this->m_totalRows;
}

float TiledMap::getScale()
{
	return this->m_scale;
}

int TiledMap::getTotalWidth()
{
	return this->getTotalCols() * this->getTileSize();
}

int TiledMap::getTotalHeight()
{
	return this->getTotalRows() * this->getTileSize();
}

std::vector<SDL_Rect> TiledMap::getColliders()
{
	return this->m_objectLayer->getColliders();
}
