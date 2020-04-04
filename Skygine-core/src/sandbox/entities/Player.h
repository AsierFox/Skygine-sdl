#pragma once

#include <spdlog/spdlog.h>
#include <SDL.h>

#include "../../entities/GameObject.h"
#include "../../input/InputHandler.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../physics/RigitBody.h"
#include "../../physics/CollisionHandler.h"
#include "../../tiledmap/TiledMap.h"
#include "../../tiledmap/TiledMapManager.h"

class Player : public GameObject
{
	SpriteAnimation* m_idleAnimation;
	SpriteAnimation* m_walkAnimation;
	SpriteAnimation* m_currentAnimation;
	RigitBody* m_rigitBody;
	TiledMap* belongsToMap;

public:

	Player(std::string id, std::string name, int x, int y);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
