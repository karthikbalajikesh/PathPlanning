#include "Grid2D.h"

// first is the default constructor
Grid2D::Grid2D() {
	// The function should create a 2D vector of graph Nodes.
	// The size of the graph nodesis currently a 2x3m grid
	// The size of each cell is 10cm. Hence we will require a 30x20 grid (y*x)
	vector<vector<GraphNode>> temp(30);
	double z_cood = -0.05, x_cood = 0; // -0.05 as the first element will become 0.5 in the for loop
	for (int z_index = 0; z_index < 30;z_index++) {
		x_cood = -1.05;
		z_cood += 0.1; // convert coordinate to meters
		for (int x_index = 0; x_index < 20;x_index++) {
			// we have divided by 20,so that we have the coordinate of the centroid
			x_cood += 0.1;
			temp[z_index].push_back(GraphNode(x_cood, z_cood));
		}
	}
	DiscretizedGrid = temp;

}

Grid2D::Grid2D(int xmax, int zmax, int cellWidth, int cellHeight) {
	// xmax in meters 
	// zmax in meters
	// cellWidth and cellHeight in cm
	// check default constructor for more details
	double z_cood = -(double)cellHeight/200;
	double x_cood = -(double)cellWidth / 200;
	int num_z = (int)((double)zmax / ((double)cellHeight/100));  // number of cells in z
	int num_x = (int)((double)xmax / ((double)cellWidth/100));   // number of cells in x
	vector<vector<GraphNode>> temp(num_z);
	for (int z_index = 0; z_index < num_z;z_index++) {
		x_cood = (-(double)cellWidth / 200) - ((double)xmax / 2);  // to shift the axis from -xmax/2 to xmax/2
		z_cood += ((double)(cellHeight) / 100); // cinvert to meters 
		for (int x_index = 0; x_index < num_x;x_index++) {
			x_cood += ((double)cellWidth / 100);
			temp[z_index].push_back(GraphNode(x_cood, z_cood));
		}
	}
	DiscretizedGrid = temp;
}

void Grid2D::ViewNodeDetails(int z_index, int x_index) {
	
	DiscretizedGrid[z_index][x_index].getCellParam();
}