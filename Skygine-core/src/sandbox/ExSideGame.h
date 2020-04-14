#pragma once

#include "../core/Engine.h"
#include "../scenes/BaseScene.h"
#include "../sandbox/scenes/TestLevelScene.h"
#include "../graphics/Camera.h"

class ExSideGame
{
	BaseScene* currentScene;

public:

	bool init();
	void events();
	void update(float delta);
	void draw();
	void dispose();
	
	bool isRunning();

	void changeScene(BaseScene* newScene);
};
