#pragma once

#include "BaseUI.h"

class Button : public BaseUI
{
	std::string m_textureId;

public:

	Button(int x, int y);

	virtual void update() override;
	virtual void draw() override;
	virtual void dispose() override;
};
