#pragma once

#include <vector>

#include "BaseScene.h"
#include "../physics/Vector2D.h"
#include "../tiledmap/TiledMap.h"
#include "../entities/Entity.h"
#include "../sandbox/entities/Enemy.h"
#include "../sandbox/entities/Player.h"

class BaseLevelScene : public BaseScene
{
protected:

	Player* m_player;
	std::vector<Entity*> m_entities;
	std::vector<Enemy*> m_enemies;

	TiledMap* m_map;

public:

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;

	TiledMap* getMap();
};
