#include<iostream>
#define ARR_SIZE 10
void shellSort(int* arr, int size){
	for(int h = size/2; h > 0; h /= 2){
		for(int i = h; i < size; i++){
			int tmp = arr[i];

			int j;
			for(j = i; j >= h && arr[j-h] > tmp; j -= h)
				arr[j] = arr[j-h];
			arr[j] = tmp;
		}
	}
}

int main(){
        int arr[ARR_SIZE] = {9, -1, 4, 9, -6, 5, 2, 1, 4, 7};
        shellSort(arr, ARR_SIZE);
        std::cout << '[';
        for(int i = 0; i < ARR_SIZE; i++)
                std::cout << arr[i] << ", " ;
        std::cout << ']';
        return 0;
}



