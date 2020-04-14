#include "Dijkstra.h"

Dijkstra::Dijkstra(pair<double,double> destination, int numIterations, int zmax, int xmax, int cellWidth, int cellHeight, int neighbours, cood_vector coordinates ) :
	PRM(numIterations,zmax,xmax,cellWidth,cellHeight,neighbours,coordinates), width(cellWidth), height(cellHeight){
	// add the destination onto the roadmap
	addDestination(destination);
}

void Dijkstra::addDestination(pair<double, double>& dest) {
	// we need to get a minHeap structure of nodes. 
	Queue distance_heap;
	GraphNode Destination(dest.second, dest.first, width, height);
	GraphNode* temp = NULL;
	int nodeIndex = 0;
	double weight = 0;
	distance_heap = FindDistance(Destination);
	int connections = 0;
	while ((!distance_heap.empty())&& connections<4) {
		nodeIndex = distance_heap.top().second;
		weight = distance_heap.top().first;
		distance_heap.pop();
		// store the address of the closest node in a pointer
		temp = &network.Vertices[nodeIndex];
		// check if the closest node is below or equal in z axis from destination
		if (temp->zcood <= Destination.zcood) {
			bool collision = collisionCheck(Destination, *temp);
			if (!collision) {
				network.AddEdge(nodeIndex, (network.numVertices) - 1, weight);
				connections++;
			}
		}

	}
}
