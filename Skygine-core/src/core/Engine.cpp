#include "Engine.h"

Engine* Engine::sp_Instance;

Engine* Engine::getInstance()
{
	if (nullptr == Engine::sp_Instance)
	{
		Engine::sp_Instance = new Engine();
	}

	return Engine::sp_Instance;
}

Engine::Engine()
{
	this->m_isRunning = true;
}

void Engine::events()
{
}

bool Engine::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		spdlog::critical("[Engine.init] SDL could not initialise! SDL Error: {0}", SDL_GetError());
	}

	return true;
}

void Engine::update(float delta)
{
}

void Engine::draw()
{
}

bool Engine::dispose()
{
	return true;
}

void Engine::quit()
{
}

bool Engine::isRunning()
{
	return this->m_isRunning;
}
