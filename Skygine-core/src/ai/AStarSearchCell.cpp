#include "AStarSearchCell.h"

AStarSearchCell::AStarSearchCell()
{
	this->parent = nullptr;
}

AStarSearchCell::AStarSearchCell(int x, int y, AStarSearchCell* parent)
{
	this->m_xCoord = x;
	this->m_yCoord = y;
	this->parent = parent;
	this->m_id = y * (25 * 16 * 3) + y;
	this->m_g = 0;
	this->m_h = 0;
}

float AStarSearchCell::getManhattanDistance(AStarSearchCell* goalNode)
{
	// TODO Check this!
	float xx = (float) (fabs(this->m_xCoord - goalNode->m_xCoord));
	float yy = (float) (fabs(this->m_yCoord - goalNode->m_yCoord));

	return xx + yy;
}

float AStarSearchCell::getF()
{
	return this->m_g + m_h;
}