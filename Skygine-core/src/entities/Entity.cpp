#include "Entity.h"

Entity::Entity(std::string id, std::string name, int x, int y, TiledMap* map)
	: GameObject(id, name, x, y, map)
{
	this->m_rigitBody = new RigitBody();
}
