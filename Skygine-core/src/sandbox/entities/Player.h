#pragma once

#include <string>

#include "../../entities/Entity.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../input/InputHandler.h"
#include "../../physics/CollisionHandler.h"
#include "../../tiledmap/TiledMap.h"

class Player : public Entity
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_walkAnimation;

	float m_maxJumpTime;
	float m_jumpTime;
	float m_JumpForce;
	bool m_isJumpling;

	float m_maxAttackTime;
	float m_attackTime;
	bool m_isAttacking;

public:

	Player(std::string id, std::string name, int x, int y, TiledMap* map);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

private:

	void input(float delta);
	void checkCollisions(float delta);
	void updateAnimationState();
};
