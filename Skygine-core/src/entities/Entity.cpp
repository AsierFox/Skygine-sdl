#include "Entity.h"

Entity::Entity(std::string id, std::string name, int x, int y)
	: GameObject(id, name, x, y)
{
	this->m_rigitBody = new RigitBody();
}
