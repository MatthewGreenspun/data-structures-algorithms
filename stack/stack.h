#ifndef STACK_H
#define STACK_H

struct Node {
	int val;
	Node* next;
	Node(int v){
		val = v;
	}
	Node(int v, Node* n){
		val = v;
		next = n;
	}
};

class IntStack {
	private:
	Node* top;
	int* values;
	int capacity;
	int curr;
	
	public:
	IntStack();
	bool empty();
	void push(int val);
	int pop();
	void resize(int newSize);
};


#endif
