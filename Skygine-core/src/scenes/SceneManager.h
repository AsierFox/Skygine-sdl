#pragma once

#include "BaseScene.h"

class SceneManager
{
	static SceneManager* s_instance;

	BaseScene* currentScene;

	SceneManager();

public:

	static SceneManager* getInstance();

	void setInitialScene(BaseScene* initialScene);

	void update(float delta);
	void render();
	void dipose();

	void switchScene(BaseScene* toScene);

	BaseScene* getCurrentScene();
};
