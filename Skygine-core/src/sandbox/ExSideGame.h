#pragma once

#include "../core/Engine.h"
#include "../tiledmap/TiledMapManager.h"
#include "entities/Player.h"

class ExSideGame
{
	Player* player;

public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();

	bool isRunning();
};
