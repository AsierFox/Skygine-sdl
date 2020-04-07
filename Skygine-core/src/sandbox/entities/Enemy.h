#pragma once

#include <SDL.h>

#include "../../entities/Entity.h"
#include "../../graphics/SpriteAnimation.h"
#include "../../graphics/TextureManager.h"

class Enemy : public Entity
{
	SpriteAnimation* m_idleAnimation;

	int m_waittingTimeCount;
	int m_waittingTime;

public:

	Enemy(std::string id, std::string name, int x, int y);

	virtual void setCollidernRegion() override;
	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
