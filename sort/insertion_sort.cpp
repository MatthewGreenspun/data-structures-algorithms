#include<iostream>
#define ARR_SIZE 10

void insertionSort(int* arr, int size){
        for(int i = 0; i < size; i++){
                for(int j = i; j > 0; j--){
                        if(arr[j] < arr[j-1]){
                                int tmp = arr[j];
                                arr[j] = arr[j-1];
                                arr[j-1] = tmp;
                        } else break;
                }
        }
}

int main(){
        int arr[ARR_SIZE] = {9, -1, 4, 9, -6, 5, 2, 1, 4, 7};
        insertionSort(arr, ARR_SIZE);
        std::cout << '[';
        for(int i = 0; i < ARR_SIZE; i++)
                std::cout << arr[i] << ", " ;
        std::cout << ']';
        return 0;
}

