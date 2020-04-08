#pragma once

#include "../core/Engine.h"
#include "../tiledmap/TiledMapManager.h"
#include "../tiledmap/TiledMap.h"
#include "../graphics/Camera.h"
#include "../entities/GameObjectFactory.h"
#include "entities/Player.h"
#include "entities/Enemy.h"

class ExSideGame
{
	TiledMap* currentMap;

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
