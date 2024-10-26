#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int length){
    int temp;
    for(int i = 0;i < length - 1;i++){
        for(int j = 0;j < length - i - 1;j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    int start, end, len, *ranArray;
    srand(time(NULL)); // 设置种子
    printf("请问你想生成多长的数组:");
    scanf("%d", &len);
    ranArray = (int *)malloc(len * sizeof(int));
    for(int n = 0;n < len;n++)
        ranArray[n] = rand() % 1000000;
    // 输入数据，生成随机数组

    printf("开始排序...\n");
    start = clock();
    bubbleSort(ranArray, len);
    end = clock();
    printf("排序完成，耗时:%dms\n", end - start);
    // 排序并计时

    free(ranArray); // 释放数组内存
    return 0;
}