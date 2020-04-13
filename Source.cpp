#include<iostream>
#include<vector>
#include<chrono>
#include"PRM.h"
using namespace std::chrono;
using namespace std;
using std::cout;
using std::cin;

#define mp make_pair 

int main() {
	// create vector of pairs of coordinates
	auto start = high_resolution_clock::now();
	vector<pair<double, double>> Coordinates;
	Coordinates.push_back(mp(0.01, -0.989));
	Coordinates.push_back(mp(0.025, -0.3)); // o(M* n^2) currently on Update Obstacles.
	Coordinates.push_back(mp(0.375, 0.4));
	Coordinates.push_back(mp(1.1, 0.6));
	Coordinates.push_back(mp(0,0));
	Coordinates.push_back(mp(2.05, 0.05));
	
	PRM map1(10, 3, 2, 1, 1, 3,Coordinates);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << duration.count();
	
	

	return 0;
}