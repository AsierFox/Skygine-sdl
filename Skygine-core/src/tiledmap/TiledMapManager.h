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
#include "TiledObject.h"

class TiledMapManager
{
	static TiledMapManager* s_instance;

	std::map<std::string, TiledMap*> m_maps;

	TiledMapManager();

public:

	static TiledMapManager* getInstance();

	TiledMap* load(std::string mapId, std::string resourcesDirPath, std::string filename, float scale);
	void dispose(std::string mapId);

	// TODO Test this without a pointer
	TiledMap* getMap(std::string mapId);
	bool isMapAlreadyLoaded(std::string mapId);
};
