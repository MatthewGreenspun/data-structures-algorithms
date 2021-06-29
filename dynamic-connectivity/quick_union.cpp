#include<iostream>
#include "DC.h"

DC::DC(int points){
	ids = new int[points];
	size = points;
	treeSizes = new int[points];

	for(int i = 0; i < points; ++i){
		ids[i] = i;
		treeSizes[i] = 1;
	}
}

DC::findRoot(int p){
	int parent = ids[p];
	while(ids[parent] != parent) {
		ids[parent] = ids[ids[parent]]; //improve performance
		parent = ids[parent];
	}
	return parent;
}

bool DC::connected(int p1, int p2){
	if(p1 >= size or p1 < 0){
		printf("%d is not in range\n", p1);
		return false;
	}
	if(p2 >= size or p2 < 0){
		printf("%d is not in range\n", p2);
		return false;
	}

	bool conn =  (findRoot(p1) == findRoot(p2));
	if(conn) printf("%d is connected to %d\n", p1, p2);
	else printf("%d is not connected to %d\n", p1, p2);
	
	return conn;
}

void DC::connect(int p1, int p2){
	if(p1 >= size or p1 < 0){
		printf("%d is not in range\n", p1);
		return; 
	}
	if(p2 >= size or p2 < 0){
		printf("%d is not in range\n", p2);
		return;
	}
	int p1Root = findRoot(p1);
	int p2Root = findRoot(p2);
	ids[p1Root] = p2Root;
}

void DC::betterConnect(int p1, int p2){
	if(p1 >= size or p1 < 0){
		printf("%d is not in range\n", p1);
		return; 
	}
	if(p2 >= size or p2 < 0){
		printf("%d is not in range\n", p2);
		return;
	}

	int p1Root = findRoot(p1);
	int p2Root = findRoot(p2);
	if(p1Root == p2Root) return;
	if(treeSizes[p1Root] < treeSizes[p2Root]){
		ids[p1Root] = p2Root;
		treeSizes[p2Root] += treeSizes[p1Root];
	}else {
		ids[p2Root] = p1Root;
		treeSizes[p1Root] += treeSizes[p2Root];
	}
}

void DC::printGraph(){
	std::cout << "Graph: " << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << i << ':' << ids[i] << std::endl;
	}
}

int main(){
	DC badDc = DC(10);
	badDc.connect(2, 4);
	badDc.connect(2, 8);
	badDc.connect(1, 8);
	badDc.connect(1, 9);
	badDc.connect(1, 7);
	badDc.connect(3, 7);
	badDc.connect(9, 8);
	badDc.printGraph();
	badDc.connected(2,1);

	DC goodDc = DC(10);
	goodDc.betterConnect(2, 4);
	goodDc.betterConnect(2, 8);
	goodDc.betterConnect(1, 8);
	goodDc.betterConnect(1, 9);
	goodDc.betterConnect(1, 7);
	goodDc.betterConnect(3, 7);
	goodDc.betterConnect(9, 8);
	goodDc.printGraph();
	goodDc.connected(2,1);

	return 0;
}

