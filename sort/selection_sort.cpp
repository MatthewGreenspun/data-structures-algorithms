#include<iostream>
#define ARR_SIZE 10

void selectionSort(int* arr, int size){
	int curr = 0; 
	for(int i = 0; i < size; i++){
		for(curr = i + 1; curr < size; curr++){
			if(arr[i] > arr[curr]){
				int tmp = arr[i];
				arr[i] = arr[curr];
				arr[curr] = tmp;
			}
		}
	}
}

int main(){
	int arr[ARR_SIZE] = {9, -1, 4, 9, -6, 5, 2, 1, 4, 7};
	selectionSort(arr, ARR_SIZE);
	std::cout << '[';
	for(int i = 0; i < ARR_SIZE; i++)
		std::cout << arr[i] << ", " ;
	std::cout << ']';
	return 0;
}
