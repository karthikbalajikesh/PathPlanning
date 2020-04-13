#pragma once
#include"GraphNode.h"
class Obstacle
{
public:
	double xmin, xmax, zmin, zmax;
	Obstacle() :xmin(100), xmax(-50), zmin(100), zmax(0) {};
	void UpdateCoordinates(GraphNode& CurrentNode) {
		// The function is to update the minimum and maximum values of an obstacle.
			xmin = (CurrentNode.xlow < xmin) ? CurrentNode.xlow:xmin;
			xmax = (CurrentNode.xhigh > xmax) ? CurrentNode.xhigh : xmax;
			zmin = (CurrentNode.zlow < zmin) ? CurrentNode.zlow : zmin;
			zmax = (CurrentNode.zhigh < zmax) ? CurrentNode.zhigh : zmax;
	}
};

