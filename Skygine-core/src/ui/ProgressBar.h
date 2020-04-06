#pragma once

#include <SDL.h>

#include "../core/Engine.h"
#include "../utils/MathUtils.h"

class ProgressBar
{
	unsigned int m_max;
	int m_min;
	int m_current;

public:

	void renderHealthBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor);

	int getPercentage();
	void setValue(int value);
};
