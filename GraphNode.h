#pragma once
class GraphNode
{
	int cellWidth, cellHeight; // is 10 cm * 10cm at this point.
public:
	// Node should contain the centroid coordinates
	double xcood, zcood;
	bool isObstacle;
	bool withinLane;
	// default constructor
	GraphNode();
	// constructor with double values
	GraphNode(double x, double z, int w=10,int h=10);
	// to get values about given cell for debugging
	// get details about the current Node
	void getCellParam();
	// tochange into obstacle
	void setObstacle();
	// check if a point is present in the cell;
	bool checkPresence(double, double);

};

