#include "ProgressBar.h"

ProgressBar::ProgressBar(int x, int y)
	: BaseUI(x, y)
{
}

void ProgressBar::update()
{
}

void ProgressBar::draw()
{
}

void ProgressBar::dispose()
{
}

void ProgressBar::renderHealthBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor) {
	Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(Engine::getInstance()->getRenderer(), &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(Engine::getInstance()->getRenderer(), &bgrect);
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int pw = (int)((float)w * Percent);
	int px = x + (w - pw);
	SDL_Rect fgrect = { px, y, pw, h };
	SDL_RenderFillRect(Engine::getInstance()->getRenderer(), &fgrect);
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), old.r, old.g, old.b, old.a);
}

int ProgressBar::getPercentage()
{
	return this->m_current;
}

void ProgressBar::setValue(int value)
{
	MathUtils::clampInt(value, this->m_min, this->m_max);

	this->m_current = value;
}
