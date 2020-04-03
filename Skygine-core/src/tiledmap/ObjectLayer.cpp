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
		TextureManager::getInstance()->renderRect(tiledObject.m_x * this->m_scale, tiledObject.m_y * this->m_scale,
			tiledObject.m_width, tiledObject.m_height, this->m_scale);
	}
}
