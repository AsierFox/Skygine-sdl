#pragma once

#include <spdlog/spdlog.h>
#include <string>
#include <vector>

#include "Layer.h"
#include "Tileset.h"
#include "../graphics/TextureManager.h"

class TileLayer : public Layer
{
	std::vector<std::vector<int> > m_tileMapIds;
	std::vector<Tileset> m_tilesets;

	void loadTilesetsTextures();

public:

	TileLayer(std::vector<std::vector<int> > tileMapIds, std::vector<Tileset> tilesets);

	void update() override;
	void render() override;
};
