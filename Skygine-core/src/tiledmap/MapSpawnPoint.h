#pragma once

#include "../physics/Point.h"
#include "MapSpawnProperty.h"

struct MapSpawnPoint
{
	Point point;
	std::vector<MapSpawnProperty> properties;
};
