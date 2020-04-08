#include "GameObject.h"

GameObject::GameObject(std::string id, std::string name, int x, int y, TiledMap* map)
{
	this->m_id = id;
	this->m_name = name;
	this->m_transform = new Transform(x, y);
	this->m_origin = new Point(x, y);
	this->belongsToMap = map;
}

Point* GameObject::getOrigin()
{
	return this->m_origin;
}
