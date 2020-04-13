#pragma once
#include"Graph.h"
#define cood_vector vector<pair<double,double>>

class PRM
{
public:
	Graph network;
	Grid2D occupancy_grid;

	// constructor
	PRM(int numIterations,int zmax = 3, int xmax = 2, int cellWidth = 10, int cellHeight = 10,int neighbours = 3, cood_vector coordinates = {});
	bool collisionCheck(GraphNode& node1, GraphNode& node2);
	void createLineEquation(double& A, double& B, double& C, GraphNode& node1, GraphNode& node2);
	bool checkDistanceMetric(double& A, double& B, double& C, Obstacle& square);
	double normDistance(double& A, double& B, double& C, double& z, double& x);
	GraphNode getRandomNode(int&, int&);
};	

