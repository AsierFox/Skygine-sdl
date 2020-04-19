#pragma once

#include <string>

#include "../../entities/Entity.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../tiledmap/TiledMap.h"
#include "../../ai/AStarFinding.h"
#include "../../physics/CollisionHandler.h"

class Enemy : public Entity
{
	SpriteAnimation* m_idleAnimation;

	AStarFinding* aStar;
	Vector2D nextCell;

public:

	Enemy(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setColliderRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
	virtual void interact(GameObject* other) override;
	virtual void proximityInteract(GameObject* other) override;

	virtual void updatePathFinding(Entity* target);

private:

	void checkCollisions(float delta);
};
