#pragma once

#include <SDL.h>

#include "../graphics/IRenderable.h"
#include "../tiledmap/TiledMap.h"
#include "../physics/Transform.h"
#include "../physics/Point.h"

class GameObject : IRenderable
{
protected:

	Transform* m_transform;
	TiledMap* belongsToMap;
	Point* m_origin;
	// TODO Review if the SDL_Rect can be encapsulated into a Collider class,
	// it can have attrs like enabled and so.
	SDL_Rect m_collider;

	std::string m_id;
	std::string m_name;

public:

	GameObject(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setCollidernRegion() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;

	Point* getOrigin();
};
