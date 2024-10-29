// 6.1 Selection
#include <stdio.h>
#define N 5

int temp;

void swap(int *m, int *n){
    temp = *m;
    *m = *n;
    *n = temp;
}

void selectSort(int arr[], int length){
    int key;
    for(int i = 0;i < length;i++){
        key = i;
        for(int k = i + 1;k < length;k++){
            if(arr[k] < arr[key]){
                key = k;
            }
        }
        swap(&arr[i], &arr[key]);
    }
}

int main(){
    int n;
    int array[N];
    printf("请输入%d个数:", N);
    for(int i = 0;i < N;i++)
        if(scanf("%d", &n) != EOF)
            array[i] = n;
        else
            return 1;
    selectSort(array, N);
    printf("排序结束为:");
    for(int i = 0;i < N;i++)
        printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
