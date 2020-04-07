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

Enemy* GameObjectFactory::createEnemy(int x, int y)
{
	this->nextEnemyId++;

	return new Enemy("enemy" + this->nextEnemyId, "Basic Enemy", x, y);
}
