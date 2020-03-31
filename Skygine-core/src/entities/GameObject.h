#pragma once

#include <SDL.h>

#include "../graphics/IRenderable.h"
#include "../physics/Transform.h"

class GameObject : IRenderable
{
protected:

	Transform* m_transform;

	std::string m_id;
	std::string m_name;

public:

	GameObject(std::string id, std::string name, int x, int y);

	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;
};