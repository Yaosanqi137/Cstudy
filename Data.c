#include <stdio.h>
#define MAX_LEN 200
#define N 4

int begin, stop, key;

void quickSort(int array[], int start, int end){
    if(end > start){
        begin = start, stop = end;
        key = array[start];
        while(end > start){
            while(array[end] >= key && end > start)
                end--;
            array[start] = array[end];
            while(array[start] <= key && end > start)
                start++;
            array[end] = array[start];
        }
        array[start] = key;
        quickSort(array, begin, start - 1);
        quickSort(array, start + 1, stop);
    }
}

int main(){
    int array[MAX_LEN], target, length = 0;
    char buffer;
    buffer = getchar();
    while(buffer != ']'){
        scanf("%d", &array[length++]);
        buffer = getchar();
    }
    quickSort(array, 0,length - 1);
}