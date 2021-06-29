#include<iostream>
#include "stack.h"

IntStack::IntStack(){
	top = nullptr;
}

bool IntStack::empty(){
	return top == nullptr;
}

void IntStack::push(int val){
	Node* newTop = new Node(val);
	newTop->next = top;
	top = newTop;
}

int IntStack::pop(){
	Node* oldTop = top;
	int value = top->val;
	top = top->next;
	delete oldTop;
	return value;
}


int main(){
	IntStack s;
	s.push(2);
	s.push(3);
	s.push(4);
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;

	return 0;
}
