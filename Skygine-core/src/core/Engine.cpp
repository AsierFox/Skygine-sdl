#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

Engine* Engine::getInstance()
{
	if (nullptr == Engine::s_Instance)
	{
		Engine::s_Instance = new Engine;
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
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		spdlog::critical("[Engine::init] SDL could not initialise SDL_INIT_VIDEO: {0}", SDL_GetError());
		return false;
	}

	SDL_WindowFlags windowFlags = (SDL_WindowFlags) (SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	this->m_window = SDL_CreateWindow("Skygine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, windowFlags);

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

	SDL_SetRenderDrawColor(this->m_renderer, 124, 218, 254, 255);

	if (SDL_Init(IMG_INIT_JPG | IMG_INIT_PNG))
	{
		spdlog::critical("[Engine::init] SDL could not initialise IMG_INIT_JPG | IMG_INIT_PNG: {0}", SDL_GetError());
		return false;
	}

	if (TTF_Init() < 0 || TTF_WasInit() == 0)
	{
		spdlog::critical("[Engine::init] SDL could not initialise TTF: {0}", SDL_GetError());
		return false;
	}

	if (Mix_Init(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) < 0)
	{
		spdlog::critical("[Engine::init] SDL could not initialise Mixer: {0}", SDL_GetError());
		return false;
	}

	spdlog::debug("[Engine::init] Initialization success!");

	return true;
}

void Engine::events()
{
	InputHandler::getInstance()->listen();
}

void Engine::update(float delta)
{
}

void Engine::drawStart()
{
	SDL_SetRenderDrawColor(this->m_renderer, 124, 218, 254, 255);
	SDL_RenderClear(this->m_renderer);
}

void Engine::drawEnd()
{
	SDL_RenderPresent(this->m_renderer);
}

void Engine::dispose()
{
	TextureManager::getInstance()->dispose();

	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
	
	Mix_Quit();
	Mix_CloseAudio();
	TTF_Quit();
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

void Engine::getWindowSize(int* width, int* height)
{
	SDL_GetWindowSize(this->m_window, width, height);
}
