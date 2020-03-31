#pragma once

#include <vector>

#include "Layer.h"

class TiledMap
{
	std::vector<Layer*> m_layers;

public:

	void update();
	void render();
};
