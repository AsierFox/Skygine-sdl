#pragma once

#include <string>

#include "GameObject.h"
#include "../graphics/SpriteAnimation.h"
#include "../physics/RigitBody.h"
#include "../tiledmap/TiledMap.h"

class Entity : public GameObject
{
protected:

	SpriteAnimation* m_currentAnimation;
	RigitBody* m_rigitBody;
	Vector2D m_lastSafePosition;

	TiledMap* belongsToMap;

	float m_speed;

public:
	
	Entity(std::string id, std::string name, int x, int y);

	virtual void setCollidernRegion() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;

};
