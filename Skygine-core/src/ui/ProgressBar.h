#pragma once

#include <SDL.h>

#include "BaseUI.h"
#include "../core/Engine.h"
#include "../utils/MathUtils.h"

class ProgressBar : public BaseUI
{
	unsigned int m_max;
	int m_min;
	int m_current;

public:

	ProgressBar(int x, int y);

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;

	void renderHealthBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor);

	int getPercentage();
	void setValue(int value);
};
