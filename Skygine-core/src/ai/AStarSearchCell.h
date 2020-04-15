#pragma once

#include <cmath>

class AStarSearchCell
{
public:

	int m_id;
	int m_xCoord;
	int m_yCoord;

	// Distance between start node and current node
	int m_g;
	// Heuristic value is the estimated distance to the goal
	int m_h;

	AStarSearchCell* parent;

	AStarSearchCell();
	AStarSearchCell(int id, int x, int y, AStarSearchCell* parent);

	// Direct/Straight distance between start node to goal node
	int getManhattanDistance(AStarSearchCell* goalNode);
	void setManhattanDistanceToHeuristic(AStarSearchCell* goalNode);
	// Direct/Straight distance between start node to goal node with diagonal
	int getEuclideanDistance(AStarSearchCell* goalNode);

	// G + H
	int getF();
};
