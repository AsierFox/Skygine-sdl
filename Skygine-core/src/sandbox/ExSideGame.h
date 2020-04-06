#pragma once

#include "../core/Engine.h"
#include "../tiledmap/TiledMapManager.h"
#include "../graphics/Camera.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

class ExSideGame
{
	Player* player;
	Enemy* enemy;

public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();
	
	bool isRunning();
};
