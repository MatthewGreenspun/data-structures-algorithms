#include<iostream>
#define ARR_SIZE 100000

void merge(int* arr, int* aux, int low, int mid, int high){
	for(int k = low; k <= high; k++)
		aux[k] = arr[k];

	int i = low;
	int j = mid + 1;
	for(int k = low; k <= high; k++){
		if(i > mid) 		arr[k] = aux[j++];
		else if(j > high) 	arr[k] = aux[i++];
		else if(aux[j] < aux[i])arr[k] = aux[j++];
		else 			arr[k] = aux[i++];
	}
}

void sort(int* arr, int* aux, int low, int high){
	if(high <= low) return;
	int mid = low + (high - low) / 2;
	sort(arr, aux, low, mid);
	sort(arr, aux, mid + 1, high);
	merge(arr, aux, low, mid, high);
}

void mergeSort(int* arr, int size){
	int* aux = new int[size];
	sort(arr, aux, 0, size-1);
	delete[] aux;
}

int main(){
        int arr[ARR_SIZE];
	for(int i = 0; i < ARR_SIZE; i++) arr[i] = ARR_SIZE - i;
        mergeSort(arr, ARR_SIZE);
        std::cout << '[';
        for(int i = 0; i < ARR_SIZE; i++)
                std::cout << arr[i] << ", " ;
        std::cout << ']';
        return 0;
}

