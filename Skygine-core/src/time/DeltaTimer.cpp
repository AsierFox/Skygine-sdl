#include "DeltaTimer.h"

DeltaTimer* DeltaTimer::s_instance;

DeltaTimer::DeltaTimer()
{
}

DeltaTimer* DeltaTimer::getInstance()
{
	if (nullptr == DeltaTimer::s_instance)
	{
		DeltaTimer::s_instance = new DeltaTimer;
	}
	return DeltaTimer::s_instance;
}

void DeltaTimer::tick()
{
	this->m_deltaTime = (SDL_GetTicks() - this->m_lastTime) * (TARGET_FPS / 1000.0f);

	if (this->m_deltaTime > TARGET_DELTATIME)
	{
		this->m_deltaTime = TARGET_DELTATIME;
	}

	this->m_lastTime = SDL_GetTicks();
}

float DeltaTimer::getDeltaTime()
{
	return this->m_deltaTime;
}
