#pragma once

#include "GameObject.h"
#include "../physics/RigitBody.h"
#include "../physics/Vector2D.h"
#include "../graphics/SpriteAnimation.h"
#include "../tiledmap/TiledMap.h"

class Entity : public GameObject
{
protected:

	SpriteAnimation* m_currentAnimation;

	RigitBody* m_rigitBody;
	Vector2D m_lastSafePosition;

	float m_speed;

public:
	
	Entity(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setColliderRegion() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
	virtual void interact(GameObject* other) = 0;
	virtual void proximityInteract(GameObject* other) = 0;
};
