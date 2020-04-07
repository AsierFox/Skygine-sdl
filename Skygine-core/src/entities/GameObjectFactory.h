#pragma once

#include "../sandbox/entities/Enemy.h"

class GameObjectFactory
{
	static GameObjectFactory* s_instance;

	unsigned int nextEnemyId;

	GameObjectFactory();

public:

	static GameObjectFactory* getInstance();

	// TODO Pass enemy type in future
	Enemy* createEnemy(int x, int y);
};
