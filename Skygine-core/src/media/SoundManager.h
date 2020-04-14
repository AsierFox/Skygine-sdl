#pragma once

#include <map>
#include <string>

#include <SDL_mixer.h>
#include <spdlog/spdlog.h>

#define FREQUENCY 44100
#define CHUNK_SIZE 2048

class SoundManager
{
	static SoundManager* s_instance;

	std::map<std::string, Mix_Music*> m_loadedMusic;
	std::map<std::string, Mix_Chunk*> m_loadedEffects;

	SoundManager();

public:

	static SoundManager* getInstace();

	void loadMusic(std::string id, std::string resourcePath);
	void loadEffect(std::string id, std::string resourcePath);
	void playMusic(std::string id);
	void playEffect(std::string id);
	void disposeMusic(std::string id);
	void disposeEffect(std::string id);
	void dispose();
};
