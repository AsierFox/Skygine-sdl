#pragma once

#include <vector>

#include "Layer.h"
#include "Tileset.h"
#include "../graphics/TextureManager.h"

class TileLayer : public Layer
{
	std::vector<std::vector<int> > m_tileMapIds;
	std::vector<Tileset> m_tilesets;
	float m_scale;

	void loadTilesetsTextures();

public:

	TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets);
	TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets, float scale);

	void update() override;
	void render() override;
};
