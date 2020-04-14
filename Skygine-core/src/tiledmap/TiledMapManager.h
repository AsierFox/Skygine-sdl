#pragma once

#include <map>
#include <string>
#include <fstream>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

#include "TiledMap.h"

class TiledMapManager
{
	static TiledMapManager* s_instance;

	std::map<std::string, TiledMap*> m_maps;

	TiledMapManager();

public:

	static TiledMapManager* getInstance();

	TiledMap* load(std::string mapId, std::string resourcesDirPath, std::string filename, float scale);
	void dispose(std::string mapId);

	TiledMap* getMap(std::string mapId);
	bool isMapAlreadyLoaded(std::string mapId);
};
