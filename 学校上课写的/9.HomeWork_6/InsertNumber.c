// 6.4
#include <stdio.h>

int temp;

void swap(int *m, int *n){
    temp = *m;
    *m = *n;
    *n = temp;
}

void sampleSort(int arr[], int lastTerm){
    for(int k = lastTerm;k > 0;k--){
        if (arr[k - 1] <= arr[k])
            break;
        swap(&arr[k], &arr[k - 1]);
    }
}

int main(){
    int arr[10] = {2, 3,7 , 9, 10, 12, 15, 16, 18};
    printf("原数组为:");
    for(int i = 0;i < 9;i++){
        printf("%d ", arr[i]);
    }
    printf("\n请输入x:");
    scanf("%d", &arr[9]);
    sampleSort(arr, 9);
    printf("新数组为:");
    for(int i = 0;i < 10;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
