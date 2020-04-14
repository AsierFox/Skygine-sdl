#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <spdlog/spdlog.h>

#include "../graphics/TextureManager.h"
#include "../input/InputHandler.h"

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
	void getWindowSize(int* width, int* height);
};
