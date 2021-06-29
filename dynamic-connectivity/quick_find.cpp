#include<iostream>
#include "DC.h"

DC::DC(int points){
	ids = new int[points];
	size = points;

	for(int i = 0; i < points; ++i){
		ids[i] = i;
	}
}


bool DC::connected(int p1, int p2){
	return (ids[p1] == ids[p2]);
}

void DC::connect(int p1, int p2){
	int p1Id = ids[p1];
	int p2Id = ids[p2];
	for(int i = 0; i < size; i++)
		if(ids[i] == p1Id) ids[i] = p2Id;
}

void DC::printGraph(){
	std::cout << "Graph: " << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << i << ':' << ids[i] << std::endl;
	}
}

int main(){
	DC dc = DC(10);
	dc.printGraph();
	dc.connect(2, 4);
	dc.connect(2, 8);
	dc.connect(3, 7);
	dc.connect(1, 9);
	dc.printGraph();

	return 0;
}
