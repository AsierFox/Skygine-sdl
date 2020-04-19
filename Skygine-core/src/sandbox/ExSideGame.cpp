#include "ExSideGame.h"

bool ExSideGame::init()
{
	bool isEngineInit = Engine::getInstance()->init();

	if (!isEngineInit)
	{
		return false;
	}

	this->currentScene = new TestLevelScene();

	return true;
}

void ExSideGame::events()
{
	Engine::getInstance()->events();
}

void ExSideGame::update(float delta)
{
	Engine::getInstance()->update(delta);

	this->currentScene->update(delta);

	Camera::getInstance()->update();
}

void ExSideGame::draw()
{
	Engine::getInstance()->drawStart();

	this->currentScene->draw();

	Engine::getInstance()->drawEnd();
}

void ExSideGame::dispose()
{
	this->currentScene->dispose();

	Engine::getInstance()->dispose();
}

bool ExSideGame::isRunning()
{
	return Engine::getInstance()->isRunning();
}

void ExSideGame::changeScene(BaseScene* newScene)
{
	BaseScene* previousScene = this->currentScene;

	this->currentScene = newScene;

	previousScene->dispose();
}
