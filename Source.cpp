#include<iostream>
#include"Grid2D.h"

using namespace std;

int main() {
	Grid2D grid(2,3,5, 5);
	int n1, n2;
	cin >> n1 >> n2;
	grid.ViewNodeDetails(n1-1, n2-1);

	return 0;
}