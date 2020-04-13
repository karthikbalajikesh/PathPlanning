#include "GraphNode.h"
#include<iostream>
using std::pair;
#pragma once
// default constructor
GraphNode::GraphNode():cellWidth(10),cellHeight(10),xcood(0.0),zcood(0.0),isObstacle(false),withinLane(true) {
	xlow = xcood - ((double)cellWidth / 200);
	xhigh = xcood + ((double)cellWidth / 200);
	zlow = zcood - ((double)cellHeight / 200);
	zhigh = zcood + ((double)cellHeight / 200);
}

// xcood zcood constructor
GraphNode::GraphNode(double x, double z, int w, int h) : cellWidth(w), cellHeight(h), xcood(x),
zcood(z), isObstacle(false), withinLane(true) {
	xlow = xcood - ((double)cellWidth / 200);
	xhigh = xcood + ((double)cellWidth / 200);
	zlow = zcood - ((double)cellHeight / 200);
	zhigh = zcood + ((double)cellHeight / 200);
}


void GraphNode::getCellParam() {
	std::cout << std::endl;
	std::cout<< " Given Node has these Parameters:\n";
	std::cout << "Cell Width = " << cellWidth << "\tCell Height = " << cellHeight << std::endl;
	std::cout << "Centroid x coordinate = " << xcood << "\t z coordinate = " << zcood<<std::endl;
	if (isObstacle) {
		std::cout << " This node is an obstacle" << std::endl;
	}
	else {
		std::cout << " This node is not an Obstacle" << std::endl;
	}
	if (withinLane) {
		std::cout << " This node is within Lane Boundaries" << std::endl;
	}
	else {
		std::cout << " This node is outside Lane Boundaries";
	}
}

void GraphNode::setObstacle() {
	isObstacle = true;
}

pair<int, int> GraphNode::getWidthHeight() {
	return (std::make_pair(cellWidth, cellHeight));
}

bool GraphNode::checkPresence(pair<double,double>& Coordinate) {
	double x = Coordinate.second;
	double z = Coordinate.first;
	

	// check if in bounds in both x and y
	if ((x >= xlow && x <= xhigh) && (z >= zlow && z <= zhigh)) {
		return true;
	}
	else {
		return false;
	}

}

// maybe include check presence x and z 