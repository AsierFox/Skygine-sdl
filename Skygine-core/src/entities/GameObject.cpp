#include "GameObject.h"

GameObject::GameObject(std::string id, std::string name, int x, int y, TiledMap* map)
{
	this->m_id = id;
	this->m_name = name;
	this->m_transform = new Transform(x, y);
	this->m_origin = new Point(x, y);
	this->belongsToMap = map;
	this->m_type = GameObjectType::DEFAULT;

	this->m_isDisabled = false;
	this->m_wantsRemove = false;
}

Point* GameObject::getOrigin()
{
	return this->m_origin;
}

Vector2D GameObject::getMapCellCoords()
{
	return Vector2D(this->getMapCellCoordX(), this->getMapCellCoordY());
}

int GameObject::getMapCellCoordX()
{
	return (int) (this->m_origin->x / belongsToMap->getTileSize());
}

int GameObject::getMapCellCoordY()
{
	return (int) (this->m_origin->y / belongsToMap->getTileSize());
}

SDL_Rect GameObject::getCollider()
{
	return this->m_collider;
}

GameObjectType GameObject::getType()
{
	return this->m_type;
}

bool GameObject::isDisabled()
{
	return this->m_isDisabled;
}

bool GameObject::wantsRemove()
{
	return this->m_wantsRemove;
}
