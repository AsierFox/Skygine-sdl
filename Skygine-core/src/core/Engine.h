#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>
#include <SDL_image.h>

#include "../graphics/TextureManager.h"

class Engine
{
	static Engine* s_Instance;

	bool m_isRunning;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

protected:

	Engine();

public:

	static Engine* getInstance();

	bool init();
	void events();
	void update(float delta);
	void drawStart();
	void drawEnd();
	void dispose();
	void quit();

	bool isRunning();
	SDL_Renderer* getRenderer();
};
