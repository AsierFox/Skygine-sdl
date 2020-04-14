#include "TileLayer.h"

void TileLayer::loadTilesetsTextures()
{
	for (unsigned int i = 0; i < this->m_tilesets.size(); i++)
	{
		Tileset tileset = this->m_tilesets[i];

		TextureManager::getInstance()->load(tileset.m_name, tileset.m_resourcePath);
	}
}

TileLayer::TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets)
	: TileLayer(tileMapIds, tilesets, 1)
{
}

TileLayer::TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets, float scale)
{
	this->m_tileMapIds = tileMapIds;
	this->m_tilesets = tilesets;
	this->m_scale = scale;

	this->loadTilesetsTextures();
}


void TileLayer::update()
{
}

void TileLayer::render()
{
	for (unsigned int row = 0; row < this->m_tileMapIds.size(); row++)
	{
		for (unsigned int col = 0; col < this->m_tileMapIds[row].size(); col++)
		{
			int tileId = this->m_tileMapIds[row][col];

			if (0 == tileId)
			{
				continue;
			}

			for (unsigned int i = 0; i < this->m_tilesets.size(); i++)
			{
				Tileset tileset = this->m_tilesets[i];

				if (tileId >= tileset.m_firstId && tileId <= tileset.m_lastId)
				{
					TextureManager::getInstance()->renderFrame(tileset.m_name,
						col * tileset.m_totalTileSize, row * tileset.m_totalTileSize,
						tileset.m_tileSize, tileset.m_tileSize, tileset.m_totalTileSize, tileset.m_totalTileSize,
						(tileId - tileset.m_firstId) % tileset.m_totalCols, (tileId - tileset.m_firstId) / tileset.m_totalCols);

					//SDL_Rect tileRect = {
					//	col * tileset.m_totalTileSize, row * tileset.m_totalTileSize,
					//	tileset.m_totalTileSize, tileset.m_totalTileSize };
					//TextureManager::getInstance()->renderRect(tileRect);
					break;
				}
			}
		}
	}
}
