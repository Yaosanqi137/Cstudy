// 6.1 insert
#include <stdio.h>
#define N 5
#define M 1

int temp;

void swap(int *m, int *n){
    temp = *m;
    *m = *n;
    *n = temp;
}

void selectSort(int arr[], int length){
    for(int i = 1;i < length;i++){
        for(int k = i;k > 0;k--){
            if(arr[k - 1] <= arr[k])
                break;
            swap(&arr[k], &arr[k - 1]);
        }
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
    if(M)
        for(int i = 0;i < N;i++)
            printf("%d ", array[i]);
    else
        for(int i = N - 1;i >= 0;i--)
            printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
