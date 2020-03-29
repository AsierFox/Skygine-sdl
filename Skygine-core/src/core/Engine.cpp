#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine* Engine::getInstance()
{
	if (nullptr == Engine::s_Instance)
	{
		Engine::s_Instance = new Engine();
	}

	return Engine::s_Instance;
}

Engine::Engine()
{
	this->m_isRunning = true;

	this->m_window = nullptr;
	this->m_renderer = nullptr;
}

bool Engine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		spdlog::critical("[Engine::init] SDL could not initialise SDL_INIT_VIDEO: {0}", SDL_GetError());
		return false;
	}

	if (SDL_Init(IMG_INIT_JPG | IMG_INIT_PNG))
	{
		spdlog::critical("[Engine::init] SDL could not initialise IMG_INIT_JPG | IMG_INIT_PNG: {0}", SDL_GetError());
		return false;
	}

	this->m_window = SDL_CreateWindow("Skygine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, 0);

	if (nullptr == this->m_window)
	{
		spdlog::critical("[Engine::init] Error creating Window: {0}", SDL_GetError());
		return false;
	}

	this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (nullptr == this->m_renderer)
	{
		spdlog::critical("[Engine::init] Error creating Renderer: {0}", SDL_GetError());
		return false;
	}

	spdlog::debug("[Engine::init] Initialization success!");

	return true;
}

void Engine::events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		this->quit();
		break;
	}
}

void Engine::update(float delta)
{
}

void Engine::draw()
{
	SDL_SetRenderDrawColor(this->m_renderer, 124, 218, 254, 255);
	SDL_RenderPresent(this->m_renderer);
}

void Engine::dispose()
{
	TextureManager::getInstance()->dispose();

	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
	
	IMG_Quit();
	SDL_Quit();
}

void Engine::quit()
{
	this->m_isRunning = false;
}

bool Engine::isRunning()
{
	return this->m_isRunning;
}

SDL_Renderer* Engine::getRenderer()
{
	return this->m_renderer;
}
