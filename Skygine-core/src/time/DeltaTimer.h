#pragma once

#include <SDL.h>

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f;

class DeltaTimer
{
	static DeltaTimer* s_instance;

	float m_deltaTime;
	float m_lastTime;

	DeltaTimer();

public:

	static DeltaTimer* getInstance();

	void tick();
	float getDeltaTime();
};
