#include<iostream>
#include "stack.h"

IntStack::IntStack(){
	curr = 0;
	capacity = 2;
	values = new int[capacity];
}

bool IntStack::empty(){
        return curr == 0;
}

void IntStack::push(int val){
	if(curr == capacity) resize(capacity*2);	
	values[curr++] = val;
}

int IntStack::pop(){
	if(curr == capacity/4) resize(capacity/2);
	return values[--curr];
}

void IntStack::resize(int newSize){
	int* newValues = new int[newSize];

	for(int i = 0; i < capacity; i++){
		newValues[i] = values[i];
	}
	
	capacity = newSize;
	delete values;
	values = newValues;
}

int main(){
        IntStack* s = new IntStack();
        s->push(2);
        s->push(3);
        s->push(4);
        std::cout << s->pop() << std::endl;
        std::cout << s->pop() << std::endl;
        std::cout << s->pop() << std::endl;
	
	delete s;
        return 0;
}

