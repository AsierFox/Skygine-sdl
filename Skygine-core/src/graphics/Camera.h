#pragma once

#include <SDL.h>

#include "../physics/Vector2D.h"
#include "../physics/Point.h"
#include "../core/Engine.h"
#include "../utils/MathUtils.h"

class Camera
{
	static Camera* s_instance;

	Vector2D m_pos;
	Point* m_target;
	SDL_Rect m_viewport;

	int m_windowWidth;
	int m_windowHeight;

	int m_mapTotalWidth;
	int m_mapTotalHeight;

public:

	static Camera* getInstance();

	Camera();

	void updateTarget(Point* newTarget);
	void update(float delta);
	void drawDebug();

	void setSceneMapDimensions(int mapTotalWidth, int mapTotalHeight);
	Vector2D getPosition();
	SDL_Rect getViewport();
};
