#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "../physics/Vector2D.h"
#include "../physics/Point.h"
#include "../utils/MathUtils.h"

class Camera
{
	static Camera* s_instance;

	Vector2D m_pos;
	Point* m_target;
	SDL_Rect m_viewport;
	SDL_DisplayMode m_displayMode;

public:

	static Camera* getInstance();

	Camera();

	void update(float delta);
	void updateTarget(Point* newTarget);

	Vector2D getPosition();
	SDL_Rect getViewport();
};
