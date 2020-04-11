#pragma once

#include "BaseUI.h"
#include "../graphics/BaseSprite.h"

class Button : public BaseUI
{
	SDL_Rect m_bounds;

	BaseSprite* m_currentStateSprite;
	BaseSprite* m_normalStateSprite;
	BaseSprite* m_hoverStateSprite;

	void (*callback)();

public:

	Button(int x, int y, void (*callback)(), BaseSprite* normalStateSprite, BaseSprite* hoverStateSprite);

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;
};
