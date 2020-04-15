#include "AStarSearchCell.h"

AStarSearchCell::AStarSearchCell()
{
	this->parent = nullptr;
}

AStarSearchCell::AStarSearchCell(int id, int x, int y, AStarSearchCell* parent)
{
	this->m_id = id;
	this->m_xCoord = x;
	this->m_yCoord = y;
	this->parent = parent;
	this->m_g = 0;
	this->m_h = 0;
}

int AStarSearchCell::getManhattanDistance(AStarSearchCell* goalNode)
{
	int xx = abs(this->m_xCoord - goalNode->m_xCoord);
	int yy = abs(this->m_yCoord - goalNode->m_yCoord);

	return xx + yy;
}

void AStarSearchCell::setManhattanDistanceToHeuristic(AStarSearchCell* goalNode)
{
	this->m_h = this->getManhattanDistance(goalNode);
}

int AStarSearchCell::getEuclideanDistance(AStarSearchCell* goalNode)
{
	int xx = pow(abs(this->m_xCoord - goalNode->m_xCoord), 2);
	int yy = pow(abs(this->m_yCoord - goalNode->m_yCoord), 2);

	return sqrt(xx + yy);
}

int AStarSearchCell::getF()
{
	return this->m_g + m_h;
}
