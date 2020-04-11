#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include"GraphNode.h"

using namespace std;

class Grid2D
{
public:
	vector<vector<GraphNode>> DiscretizedGrid;
	// default constructor
	Grid2D();
	// constructor with x and y fov and mesh size
	Grid2D(int xmax, int zmax, int cellWidth, int cellHeight);
	//One method to update obstacle from a list or heap into the grid
	void UpdateObstacles(vector<pair<int, int>>);
	void UpdateObstacles(priority_queue<pair<int, int>>); // replace with an object later
	// One method to inflate cells the size of the robot
	void InflateObstacle(int i, int j);
	// viewing function
	void ViewNodeDetails(int index1, int index2);
};

