#pragma once

#include <SDL.h>

#define SECOND_IN_MILISECONDS 1000

class Timer
{
	static Timer* s_instance;

	float m_lastTime;
	float m_currentTime;

	Timer();

public:

	static Timer* getInstance();

	void tick();
};
