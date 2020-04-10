#pragma once

#include "BaseUI.h"

class Button : public BaseUI
{
public:

	Button(int x, int y);

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;
};
