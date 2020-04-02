#pragma once

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "TiledMap.h"
#include "Layer.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "Tileset.h"

class TiledMapManager
{
	static TiledMapManager* s_instance;

	std::map<std::string, TiledMap*> m_maps;

	TiledMapManager();

public:

	static TiledMapManager* getInstance();

	void load(std::string mapId, std::string resourcesDirPath, std::string filename);
	void dispose(std::string mapId);

	TiledMap* getMap(std::string mapId);
};
