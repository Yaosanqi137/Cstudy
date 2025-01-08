#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000000

int array[N];

void quickSort(int arr[], int left, int right){
    if(left < right){
        int key = arr[left], begin = left, end = right;
        while(left < right){
            while(left < right && arr[right] >= key) right--;
            arr[left] = arr[right];
            while(left < right && arr[left] <= key) left++;
            arr[right] = arr[left];
        }
        arr[left] = key;
        if(begin < left - 1)
            quickSort(arr, begin, left - 1);
        if(left + 1 < end)
            quickSort(arr, left + 1, end);
    }
}

int main(){
    srand(time(NULL));
    int start, end;
    for(int i = 0; i < N; i++)
        array[i] = rand() % 10000;
    start = clock();
    quickSort(array, 0, N);
    end = clock();
    printf("%d ms\n", end - start);
    return 0;
}