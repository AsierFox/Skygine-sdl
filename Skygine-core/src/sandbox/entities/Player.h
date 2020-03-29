#pragma once

#include <SDL.h>

#include "../../entities/GameObject.h"
#include "../../graphics/SpriteAnimation.h"

class Player : GameObject
{
	SpriteAnimation* spriteAnimation;

public:

	Player(std::string id, std::string name, int x, int y);

	virtual void update(float delta) override;
	virtual void draw() override;
	virtual void dispose() override;
};
