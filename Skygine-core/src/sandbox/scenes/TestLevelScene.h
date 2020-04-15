#pragma once

#include <SDL.h>

#include "../../scenes/BaseLevelScene.h"
#include "../../entities/GameObjectFactory.h"
#include "../../physics/Vector2D.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../scenes/BaseLevelScene.h"
#include "../../sandbox/entities/Player.h"
#include "../../graphics/Camera.h"
#include "../../graphics/TextureManager.h"
#include "../../media/FontManager.h"

class TestLevelScene : public BaseLevelScene
{
public:

	TestLevelScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
