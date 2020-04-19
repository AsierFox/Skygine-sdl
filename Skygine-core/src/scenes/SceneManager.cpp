#include "SceneManager.h"

SceneManager* SceneManager::s_instance = nullptr;

SceneManager::SceneManager()
{
	this->s_instance = nullptr;
}

SceneManager* SceneManager::getInstance()
{
	if (nullptr == SceneManager::s_instance)
	{
		SceneManager::s_instance = new SceneManager;
	}

	return SceneManager::s_instance;
}

void SceneManager::setInitialScene(BaseScene* initialScene)
{
	this->currentScene = initialScene;
}

void SceneManager::update(float delta)
{
	this->currentScene->update(delta);
}

void SceneManager::render()
{
	this->currentScene->draw();
}

void SceneManager::dipose()
{
	this->currentScene->dispose();
}

void SceneManager::switchScene(BaseScene* toScene)
{
	BaseScene* previousScene = this->currentScene;

	this->currentScene = toScene;

	previousScene->dispose();
}

BaseScene* SceneManager::getCurrentScene()
{
	return this->currentScene;
}
