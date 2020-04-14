#pragma once

#include <cmath>

class AStarSearchCell
{
public:

	int m_id;
	int m_xCoord;
	int m_yCoord;

	// Distance between start node and current node
	float m_g;
	// Heuristic value is the estimated distance to the goal
	float m_h;

	AStarSearchCell* parent;

	AStarSearchCell();
	AStarSearchCell(int x, int y, AStarSearchCell* parent);

	// Direct/Straight distance between start node to goal node
	float getManhattanDistance(AStarSearchCell* goalNode);
	// G + H
	float getF();
};
