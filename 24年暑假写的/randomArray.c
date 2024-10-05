#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>

int main(){
    printf("请输入你想生成的随机数组: ");
    int LENGTH;
    scanf("%d", &LENGTH);
    LENGTH -= 1;
    int *arr = (int*)malloc(LENGTH * sizeof(int));
    int SAVE = LENGTH;

    srand((unsigned) time(NULL));
    for(;LENGTH >= 0;LENGTH--){
        arr[LENGTH] = rand() % 100;
    }
    LENGTH = 0;
    
    int TEMP;
    for(int i = 0;i < SAVE;i++){
        for(int j = 0;j < SAVE - i;j++){
            if(arr[j] > arr[j + 1]){
                TEMP = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = TEMP;
            }
        }
    }

    for(;LENGTH <= SAVE;LENGTH++){
        printf("%d,", arr[LENGTH]);
    }

    free(arr);
    return 0;
}