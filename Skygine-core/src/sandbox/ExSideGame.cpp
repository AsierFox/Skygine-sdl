#include "ExSideGame.h"

bool ExSideGame::init()
{
	bool isEngineInit = Engine::getInstance()->init();

	if (!isEngineInit)
	{
		return false;
	}

	this->player = new Player("player", "SkyFoXx", 100, 100);

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
}

void ExSideGame::draw()
{
	Engine::getInstance()->draw();

	this->player->draw();
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
