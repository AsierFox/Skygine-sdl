#include "SoundManager.h"

SoundManager* SoundManager::s_instance = nullptr;

SoundManager::SoundManager()
{
}

SoundManager* SoundManager::getInstace()
{
	if (nullptr == SoundManager::s_instance)
	{
		SoundManager::s_instance = new SoundManager();
	}

	return SoundManager::s_instance;
}

void SoundManager::loadMusic(std::string id, std::string resourcePath)
{
	Mix_Music* music = Mix_LoadMUS(resourcePath.c_str());

	if (!music)
	{
		spdlog::debug("[SoundManager::loadMusic] Failed to load music with id '{0}' in path '{1}'!: {2}", id, resourcePath, Mix_GetError());
		return;
	}

	spdlog::debug("[SoundManager::loadMusic] Music with id '{0}' loaded successfully!", id);

	this->m_loadedMusic.insert({ id, music });
}

void SoundManager::loadEffect(std::string id, std::string resourcePath)
{
	Mix_Chunk* effect = Mix_LoadWAV(resourcePath.c_str());

	if (!effect)
	{
		spdlog::debug("[SoundManager::loadEffect] Failed to load sound effect music with id '{0}' in path '{1}'!: {2}", id, resourcePath, Mix_GetError());
		return;
	}

	spdlog::debug("[SoundManager::loadEffect] Sound effect with id '{0}' loaded successfully!", id);

	this->m_loadedEffects.insert({ id, effect });
}

void SoundManager::playMusic(std::string id)
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(this->m_loadedMusic[id], -1);
	}
	else
	{
		spdlog::debug("[SoundManager::playMusic] Can't play music with id '{0}', there is another music been played!", id);
	}
}

void SoundManager::playEffect(std::string id)
{
	Mix_PlayChannel(-1, this->m_loadedEffects[id], 0);
}

void SoundManager::disposeMusic(std::string id)
{
	Mix_FreeMusic(this->m_loadedMusic[id]);
	this->m_loadedMusic.erase(id);
}

void SoundManager::disposeEffect(std::string id)
{
	Mix_FreeChunk(this->m_loadedEffects[id]);
	this->m_loadedEffects.erase(id);
}

void SoundManager::dispose()
{
	std::map<std::string, Mix_Music*>::iterator itMusic;

	for (itMusic = this->m_loadedMusic.begin(); itMusic != this->m_loadedMusic.end(); itMusic++)
	{
		this->disposeMusic(itMusic->first);
	}
	this->m_loadedMusic.clear();

	std::map<std::string, Mix_Chunk*>::iterator itEffect;

	for (itEffect = this->m_loadedEffects.begin(); itEffect != this->m_loadedEffects.end(); itEffect++)
	{
		this->disposeEffect(itEffect->first);
	}
	this->m_loadedMusic.clear();
}
