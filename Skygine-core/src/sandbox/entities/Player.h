#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "../../entities/GameObject.h"
#include "../../input/InputHandler.h"
#include "../../input/AxisDirection.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../physics/RigitBody.h"
#include "../../physics/CollisionHandler.h"
#include "../../tiledmap/TiledMap.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../physics/Vector2D.h"

class Player : public GameObject
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_walkAnimation;
	SpriteAnimation* m_currentAnimation;
	RigitBody* m_rigitBody;
	TiledMap* belongsToMap;

	Vector2D m_lastSafePosition;

	float m_speed;

	float m_maxJumpTime;
	float m_jumpTime;
	float m_JumpForce;
	bool m_isJumpling;

	float m_maxAttackTime;
	float m_attackTime;
	bool m_isAttacking;

public:

	Player(std::string id, std::string name, int x, int y);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;

private:

	void input(float delta);
	void checkCollisions(float delta);
	void updateAnimationState();
};
