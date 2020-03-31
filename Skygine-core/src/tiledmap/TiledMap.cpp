#include "TiledMap.h"

void TiledMap::update()
{
	for (unsigned int i = 0; i < this->m_layers.size(); i++)
	{
		this->m_layers[i]->render();
	}
}

void TiledMap::render()
{
	for (unsigned int i = 0; i < this->m_layers.size(); i++)
	{
		this->m_layers[i]->render();
	}
}
