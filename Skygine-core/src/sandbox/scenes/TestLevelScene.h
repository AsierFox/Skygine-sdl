#pragma once

#include <SDL.h>

#include "../../scenes/BaseLevelScene.h"
#include "../../physics/Vector2D.h"
#include "../../tiledmap/TiledMapManager.h"
#include "../../entities/GameObjectFactory.h"
#include "../../entities/Entity.h"
#include "../entities/Player.h"
#include "../../graphics/Camera.h"
#include "../../graphics/TextureManager.h"

class TestLevelScene : public BaseLevelScene
{
	TiledMap* m_map;

	Player* m_player;
	std::vector<Entity*> m_entities;

public:

	TestLevelScene();

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
