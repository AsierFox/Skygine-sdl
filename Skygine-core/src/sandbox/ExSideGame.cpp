#include "ExSideGame.h"

bool ExSideGame::init()
{
	bool isEngineInit = Engine::getInstance()->init();

	if (!isEngineInit)
	{
		return false;
	}

	this->player = new Player("player", "SkyFoXx", 300, 300);
	
	Camera::getInstance()->updateTarget(this->player->getOrigin());

	TiledMapManager::getInstance()->load("test-map", "assets/maps/", "map-tiled.json", 3);

	return true;
}

void ExSideGame::events()
{
	Engine::getInstance()->events();
}

void ExSideGame::update(float delta)
{
	Engine::getInstance()->update(delta);

	this->player->update(delta);

	TiledMapManager::getInstance()->getMap("test-map")->update();

	Camera::getInstance()->update(delta);
}

void ExSideGame::draw()
{
	Engine::getInstance()->drawStart();

	TiledMapManager::getInstance()->getMap("test-map")->render();
	this->player->draw();
	
	Engine::getInstance()->drawEnd();
}

void ExSideGame::dispose()
{
	Engine::getInstance()->dispose();

	this->player->dispose();
}

bool ExSideGame::isRunning()
{
	return Engine::getInstance()->isRunning();
}
