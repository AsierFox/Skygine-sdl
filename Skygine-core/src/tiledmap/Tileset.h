#pragma once

#include <string>

struct Tileset
{
	int m_firstId;
	int m_lastId;
	int m_totalCols;
	int m_totalRows;
	int m_tileSize;
	int m_totalTileSize;
	std::string m_name;
	std::string m_resourcePath;
};
