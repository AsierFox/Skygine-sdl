#include "TestLevelScene.h"

TestLevelScene::TestLevelScene()
{
	this->m_map = TiledMapManager::getInstance()->load("test-map", "assets/maps/", "map-tiled.json", 5);

	this->m_player = new Player("player", "SkyFoXx", 250, 230, this->m_map);
	this->m_entities.push_back(GameObjectFactory::getInstance()->createEnemy(500, 300, this->m_map));

	Camera::getInstance()->updateTarget(this->m_player->getOrigin());
	Camera::getInstance()->setSceneMapDimensions(this->m_map->getTotalWidth(), this->m_map->getTotalHeight());

	aStar = AStarFinding();
}

void TestLevelScene::update(float delta)
{
	this->m_map->update();

	for (Entity* entity : m_entities)
	{
		entity->update(delta);
	}

	this->m_player->update(delta);

	aStar.findPath(this->m_player->getMapCellCoords(), this->m_entities[0]->getMapCellCoords());
	if (aStar.isGoalFounded())
	{
		this->nextCell = aStar.nextPathPosition(this->m_player);
	}
}

void TestLevelScene::draw()
{
	this->m_map->render();

	for (Entity* entity : m_entities)
	{
		entity->draw();
	}

	this->m_player->draw();

	SDL_Rect nextStepRect = { this->nextCell.x * (16 * 5), this->nextCell.y * (16 * 5), (16 * 5), (16 * 5) };
	TextureManager::getInstance()->renderRect(nextStepRect);
}

void TestLevelScene::dispose()
{
	// TODO Dispose everything

	this->m_player->dispose();
}
