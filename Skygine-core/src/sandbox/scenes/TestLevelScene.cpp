#include "TestLevelScene.h"

TestLevelScene::TestLevelScene()
{
	this->m_map = TiledMapManager::getInstance()->load("test-map", "assets/maps/", "map-tiled.json", 3);

	this->m_player = new Player("player", "SkyFoXx", 300, 300, this->m_map);
	this->m_entities.push_back(GameObjectFactory::getInstance()->createEnemy(500, 300, this->m_map));

	Camera::getInstance()->updateTarget(this->m_player->getOrigin());
}

void TestLevelScene::update(float delta)
{
	this->m_map->update();

	for (Entity* entity : m_entities)
	{
		entity->update(delta);
	}

	this->m_player->update(delta);
}

void TestLevelScene::draw()
{
	this->m_map->render();

	for (Entity* entity : m_entities)
	{
		entity->draw();
	}

	this->m_player->draw();
}

void TestLevelScene::dispose()
{
	// TODO Dispose everything

	this->m_player->dispose();
}
