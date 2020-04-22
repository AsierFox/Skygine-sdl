#pragma once

#include "../physics/Vector2D.h"
#include "../graphics/BaseSprite.h"

struct TiledTile
{
	Vector2D m_pos;
	std::string m_textureId;
	int m_textureFrameSize;
	int m_totalSize;
	int m_col;
	int m_row;
};
