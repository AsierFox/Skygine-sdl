#include "ObjectLayer.h"

ObjectLayer::ObjectLayer(std::vector<TiledObject> objects, float scale)
{
	this->m_objects = objects;
	this->m_scale = scale;
}

void ObjectLayer::update()
{
}

void ObjectLayer::render()
{
	for (unsigned int i = 0; i < this->m_objects.size(); i++)
	{
		TiledObject tiledObject = this->m_objects[i];
		TextureManager::getInstance()->renderRect(tiledObject.m_collider);
	}
}

std::vector<SDL_Rect> ObjectLayer::getColliders()
{
	std::vector<SDL_Rect> colliders(this->m_objects.size());

	std::transform(this->m_objects.begin(), this->m_objects.end(), colliders.begin(), [] (TiledObject const& tiledObject) {
		return tiledObject.m_collider;
	});
	
	return colliders;
}
