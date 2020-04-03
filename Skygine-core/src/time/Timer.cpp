#include "Timer.h"

Timer* Timer::s_instance;

Timer::Timer()
{
	this->m_lastTime = 0;
}

Timer* Timer::getInstance()
{
	if (nullptr == Timer::s_instance)
	{
		Timer::s_instance = new Timer;
	}
	return Timer::s_instance;
}

void Timer::tick()
{
	this->m_currentTime = SDL_GetTicks();

	if (this->m_currentTime > this->m_lastTime + SECOND_IN_MILISECONDS)
	{
		// One second passed!
		this->m_lastTime = this->m_currentTime;
	}
}
