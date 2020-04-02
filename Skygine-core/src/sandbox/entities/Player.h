#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "../../entities/GameObject.h"
#include "../../input/InputHandler.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../physics/RigitBody.h"

class Player : public GameObject
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_walkAnimation;
	SpriteAnimation* m_currentAnimation;
	RigitBody* m_rigitBody;

public:

	Player(std::string id, std::string name, int x, int y);

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
