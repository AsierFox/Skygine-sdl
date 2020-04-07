#pragma once

#include "../core/Engine.h"
#include "../tiledmap/TiledMapManager.h"
#include "../graphics/Camera.h"
#include "../entities/GameObjectFactory.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

class ExSideGame
{
	Player* player;
	Enemy* enemy;

	bool test = false;

public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();
	
	bool isRunning();
};
