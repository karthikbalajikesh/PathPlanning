#include "PRM.h"

PRM::PRM(int zmax, int xmax, int cellWidth, int cellHeight, int radius, int neighbours, cood_vector coordinates) {
	
}

// function to check if obstacle is present in between two nodes
bool PRM::collisionCheck(GraphNode& node1, GraphNode& node2) {
	// inputs are two grid nodes. we need to use the Obstacle list in Grid2D object for this. 
	
	// step 1: create equation of line
	double A = 0, B = 0, C = 0;
	createLineEquation(A, B, C, node1, node2);
	bool collision = false;
	for (int obstacle_number = 0;obstacle_number < occupancy_grid.ObstacleList.size();obstacle_number++) {
		collision = checkDistanceMetric(A, B, C, occupancy_grid.ObstacleList[obstacle_number]);
		if (collision == true) {
			return true;
		}
	}

	return collision;
	
}

void PRM::createLineEquation(double& A, double& B, double& C, GraphNode& node1, GraphNode& node2) {
	// line equation is AZ - BX + C = 0
	// where A is x2-x1, B is z2-z1, C is z2x1 - z1x2
	A = node2.xcood - node1.xcood;
	B = node2.zcood - node1.zcood;
	C = (node2.zcood * node1.xcood) + (node1.zcood * node2.xcood);


}

bool PRM::checkDistanceMetric(double& A, double& B, double& C, Obstacle& square) {
	double D1 = 0, D2 = 0, D3 = 0, D4 = 0;
	D1 = normDistance(A, B, C, square.zmin, square.xmin);
	D2 = normDistance(A, B, C, square.zmin, square.xmax);
	D3 = normDistance(A, B, C, square.zmax, square.xmax);
	D4 = normDistance(A, B, C, square.zmax, square.xmin);
	if ((D1 >= 0 && D2 >= 0 && D3 >= 0 && D4 >= 0)|| (D1 <= 0 && D2 <= 0 && D3 <= 0 && D4 <= 0)) {
		return false;
	}
	else {
		return true;
	}
	
}

double PRM::normDistance(double& A, double& B, double& C, double& z, double& x) {
	// return the norm distance without the denominator
	return ((A*z)-(B*x)+(C));
}
