#pragma once

#include <spdlog/spdlog.h>

#include "../../scenes/BaseLevelScene.h"
#include "../../entities/GameObjectFactory.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../entities/GameObjectFactory.h"
#include "../../entities/Entity.h"
#include "../entities/Player.h"

class TestLevelScene : public BaseLevelScene
{
public:

	TestLevelScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
