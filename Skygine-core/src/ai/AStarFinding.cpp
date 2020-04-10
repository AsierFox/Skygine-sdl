#include "AStarFinding.h"

AStarFinding::AStarFinding()
{
}

void AStarFinding::findPath(Vector2D currentNode, Vector2D goalNode)
{
}

Vector2D AStarFinding::nextPathPosition()
{
	return Vector2D();
}

void AStarFinding::clearOpenList()
{
	this->m_openList.clear();
}

void AStarFinding::clearVisitedList()
{
	this->m_visitedList.clear();
}

void AStarFinding::clearPathToGoal()
{
	this->m_shortestPath.clear();
}

void AStarFinding::setStartAndGoal(AStarSearchCell start, AStarSearchCell goal)
{
}

void AStarFinding::isInOpenedList(int x, int y, float newCost, AStarSearchCell* parent)
{
}

AStarSearchCell* AStarFinding::getNextCell()
{
	return nullptr;
}

void AStarFinding::continuePath()
{
}
