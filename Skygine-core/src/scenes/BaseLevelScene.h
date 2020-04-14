#pragma once

#include <vector>

#include "BaseScene.h"

class BaseLevelScene : public BaseScene
{
protected:

public:

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
};
