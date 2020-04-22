#include "TileLayer.h"

TileLayer::TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets)
	: TileLayer(tileMapIds, tilesets, 1)
{
}

TileLayer::TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets, float scale)
{
	this->m_scale = scale;

	this->loadTilesetsTextures(tilesets);
	this->loadTiles(tileMapIds, tilesets);
}


void TileLayer::update()
{
}

void TileLayer::render()
{
	for (TiledTile tile : this->m_tiles)
	{
		TextureManager::getInstance()->renderFrame(tile.m_textureId,
			tile.m_pos.x, tile.m_pos.y,
			tile.m_textureFrameSize, tile.m_textureFrameSize,
			tile.m_totalSize, tile.m_totalSize,
			tile.m_col, tile.m_row);
	}
}

void TileLayer::loadTilesetsTextures(std::vector<Tileset> tilesets)
{
	for (unsigned int i = 0; i < tilesets.size(); i++)
	{
		Tileset tileset = tilesets[i];

		TextureManager::getInstance()->load(tileset.m_name, tileset.m_resourcePath);
	}
}

void TileLayer::loadTiles(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets)
{
	for (unsigned int row = 0; row < tileMapIds.size(); row++)
	{
		for (unsigned int col = 0; col < tileMapIds[row].size(); col++)
		{
			int tileId = tileMapIds[row][col];

			if (0 == tileId)
			{
				continue;
			}

			for (unsigned int i = 0; i < tilesets.size(); i++)
			{
				Tileset tileset = tilesets[i];

				if (tileId >= tileset.m_firstId && tileId <= tileset.m_lastId)
				{
					TiledTile tile;

					tile.m_textureId = tileset.m_name;

					tile.m_pos.x = col * tileset.m_totalTileSize;
					tile.m_pos.y = row * tileset.m_totalTileSize;

					tile.m_textureFrameSize = tileset.m_tileSize;
					tile.m_totalSize = tileset.m_totalTileSize;

					tile.m_col = (tileId - tileset.m_firstId) % tileset.m_totalCols;
					tile.m_row = (tileId - tileset.m_firstId) / tileset.m_totalCols;

					this->m_tiles.push_back(tile);

					break;
				}
			}
		}
	}
}
