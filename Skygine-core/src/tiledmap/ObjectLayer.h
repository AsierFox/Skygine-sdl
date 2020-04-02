#pragma once

#include "Layer.h"

class ObjectLayer : public Layer
{
public:

	ObjectLayer();

	void update() override;
	void render() override;
};
