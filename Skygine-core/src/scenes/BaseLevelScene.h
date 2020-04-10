#pragma once

#include <vector>

#include "BaseScene.h"
#include "../tiledmap/TiledMap.h"
#include "../entities/Entity.h"
#include "../sandbox/entities/Player.h"

class BaseLevelScene : public BaseScene
{
protected:
	
	TiledMap* m_map;

	Player* m_player;
	std::vector<Entity*> m_entities;

public:

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
};
