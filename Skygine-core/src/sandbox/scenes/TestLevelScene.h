#pragma once

#include <spdlog/spdlog.h>

#include "../../scenes/BaseLevelScene.h"
#include "../../entities/GameObjectFactory.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../entities/GameObjectFactory.h"
#include "../../entities/Entity.h"
#include "../entities/Player.h"
#include "../../ai/AStarFinding.h"

class TestLevelScene : public BaseLevelScene
{
	AStarFinding aStar;

	Vector2D nextCell;

public:

	TestLevelScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
