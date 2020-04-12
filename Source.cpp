#include<iostream>
#include<vector>
#include"Grid2D.h"

using namespace std;
using std::cout;
using std::cin;

#define mp make_pair 

int main() {
	Grid2D grid(2,3);
	// create vector of pairs of coordinates
	vector<pair<double, double>> Coordinates;
	Coordinates.push_back(mp(0.01, -0.989));
	Coordinates.push_back(mp(0.025, -0.3)); // check bugs in implementation of update obstacle
	Coordinates.push_back(mp(0.375, 0.4));
	Coordinates.push_back(mp(1.1, 0.6));
	Coordinates.push_back(mp(2.05, 0.05));
	
	grid.UpdateObstacles(Coordinates);
	grid.ViewNodeDetails(1, 1);
	grid.ViewNodeDetails(1, 12);
	grid.ViewNodeDetails(15, 11);
	grid.ViewNodeDetails(1,10);
	return 0;
}