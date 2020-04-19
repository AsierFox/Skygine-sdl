#pragma once

#include <SDL.h>

#include <string>

#include "../graphics/IRenderable.h"
#include "../physics/Transform.h"
#include "../physics/Point.h"
#include "../physics/Vector2D.h"
#include "../tiledmap/TiledMap.h"
#include "../types/GameObjectType.h"

class GameObject : IRenderable
{
protected:

	TiledMap* belongsToMap;
	Transform* m_transform;
	Point* m_origin;
	// TODO Review if the SDL_Rect can be encapsulated into a Collider class,
	// it can have attrs like enabled and so. (Move inside collider (?))
	SDL_Rect m_collider;

	std::string m_id;
	std::string m_name;

	GameObjectType m_type;

	bool m_isDisabled;
	bool m_wantsRemove;

public:

	GameObject(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setColliderRegion() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
	virtual void interact(GameObject* other) = 0;
	virtual void proximityInteract(GameObject* other) = 0;

	Point* getOrigin();
	Vector2D getMapCellCoords();
	int getMapCellCoordX();
	int getMapCellCoordY();
	SDL_Rect getCollider();
	GameObjectType getType();
	bool isDisabled();
	bool wantsRemove();
};
