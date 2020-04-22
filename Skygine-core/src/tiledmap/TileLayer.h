#pragma once

#include <vector>

#include "Layer.h"
#include "Tileset.h"
#include "../graphics/TextureManager.h"
#include "../tiledmap/TiledTile.h"

class TileLayer : public Layer
{
	std::vector<TiledTile> m_tiles;
	float m_scale;

public:

	TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets);
	TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets, float scale);

	void update() override;
	void render() override;

private:

	void loadTilesetsTextures(std::vector<Tileset> tilesets);
	void loadTiles(std::vector<std::vector<int> > m_tileMapIds, std::vector<Tileset> tilesets);
};
