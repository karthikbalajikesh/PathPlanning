#pragma once
#include "PRM.h"

class Dijkstra :
	public PRM
{	
public:
	int width, height;
	vector<int> path;
	// constructor
	Dijkstra(pair<double,double> destination,int numIterations = 100, int zmax = 1, int xmax = 2,
		int cellWidth = 10, int CellHeight = 10, int neighbours = 3, cood_vector coordinates = {});
	void addDestination(pair<double,double>& dest);
	vector<GraphNode> shortestPath();
};

