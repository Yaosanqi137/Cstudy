// 6.2 bubble
#include <stdio.h>
#define N 5

void bubbleSort(int arr[], int length){
    int temp;
    for(int j = 0;j < length;j++){
        for(int k = 0;k < length - j - 1;k++){
            if(arr[k] > arr[k + 1]){
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
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
    bubbleSort(array, N);
    for(int i = 0;i < N;i++)
        printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
