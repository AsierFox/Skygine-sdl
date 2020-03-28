#pragma once

#include <SDL.h>
#include <spdlog/spdlog.h>

class Engine
{
	static Engine* sp_Instance;

	bool m_isRunning;

	Engine();

public:

	static Engine* getInstance();

	void events();
	bool init();
	void update(float delta);
	void draw();
	bool dispose();
	void quit();

	bool isRunning();
};
