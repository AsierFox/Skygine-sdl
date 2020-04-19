#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::s_instance = nullptr;

GameObjectFactory::GameObjectFactory()
{
	this->nextEnemyId = 0;
}

GameObjectFactory* GameObjectFactory::getInstance()
{
	if (nullptr == GameObjectFactory::s_instance)
	{
		GameObjectFactory::s_instance = new GameObjectFactory();
	}

	return GameObjectFactory::s_instance;
}

Enemy* GameObjectFactory::createEnemy(int x, int y, TiledMap* map)
{
	this->nextEnemyId++;

	// TODO Refactor to Flightweight design pattern (creating a map of objects)
	return new Enemy("enemy" + std::to_string(this->nextEnemyId), "Basic Enemy", x, y, map);
}
