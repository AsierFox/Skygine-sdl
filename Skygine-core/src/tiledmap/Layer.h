#pragma once

struct Layer
{
	virtual void update() = 0;
	virtual void render() = 0;
};
