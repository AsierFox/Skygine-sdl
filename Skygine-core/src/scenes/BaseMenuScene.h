#pragma once

#include <vector>

#include "BaseScene.h"

class BaseMenuScene : public BaseScene
{
protected:

	std::vector<BaseUI*> m_uiComponents;

public:

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
};
