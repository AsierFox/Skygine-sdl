#include "TestLevelScene.h"

TestLevelScene::TestLevelScene()
{
	this->m_map = TiledMapManager::getInstance()->load("test-map", "assets/maps/", "map-tiled.json", 5);

	this->m_player = new Player("player", "SkyFoXx", 250, 230, this->m_map);
	this->m_entities.push_back(GameObjectFactory::getInstance()->createEnemy(500, 300, this->m_map));
	this->m_enemies.push_back(GameObjectFactory::getInstance()->createEnemy(400, 350, this->m_map));

	Camera::getInstance()->updateTarget(this->m_player->getOrigin());
	Camera::getInstance()->setSceneMapDimensions(this->m_map->getTotalWidth(), this->m_map->getTotalHeight());
}

void TestLevelScene::update(float delta)
{
	this->m_map->update();

	this->m_player->update(delta);

	for (Entity* entity : this->m_entities)
	{
		entity->update(delta);
	}

	for (Enemy* enemy : this->m_enemies)
	{
		enemy->updatePathFinding(this->m_player);
		enemy->update(delta);
	}
}

void TestLevelScene::draw()
{
	this->m_map->render();

	for (Entity* entity : this->m_entities)
	{
		entity->draw();
	}

	for (Enemy* enemy : this->m_enemies)
	{
		enemy->draw();
	}

	this->m_player->draw();
}

void TestLevelScene::dispose()
{
	// TODO Dispose everything

	this->m_player->dispose();
	delete this->m_player;
}
