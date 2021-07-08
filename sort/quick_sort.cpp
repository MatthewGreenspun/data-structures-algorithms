#include<iostream>
#define ARR_SIZE 10

void exchange(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

bool less(int num1, int num2){return (num1 < num2);}

int partition(int* arr, int low, int high){
	int i = low;
	int j = high+1;
	while(true){
		while(less(arr[++i], arr[low]))
			if(i == high) break;
		while(less(arr[low], arr[--j]))
			if(j == low) break;

		if(i >= j) break;
		exchange(arr, i, j);
	}
	exchange(arr, low, j);
	return j;
}

void sort(int* arr, int low, int high){
	if(high <= low) return;
	int pivot = partition(arr, low, high);
	sort(arr, low, pivot-1);
	sort(arr, pivot+1, high);
}

void quickSort(int* arr, int size){
	sort(arr, 0, size - 1);
}

int main(){
        int arr[ARR_SIZE] = {9, -1, -4, 10, -6, 5, 2, 1, 4, 7};
        quickSort(arr, ARR_SIZE);
        std::cout << '[';
        for(int i = 0; i < ARR_SIZE; i++)
                std::cout << arr[i] << ", " ;
        std::cout << ']';
        return 0;
}

