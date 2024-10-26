#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//快速排序法
void quickSort(int array[], int left, int right){
    int key = array[left], start = left, end = right;
    // 记录 key, 左右的值

    while(left < right){
        while(left < right && array[right] >= key)
            right--;
        array[left] = array[right]; // 在右边比左边小的时候替换
        while(left < right && array[left] <= key)
            left++;
        array[right] = array[left]; // 在左边比右边大的时候替换
    }
    array[left] = key; // 左右分组完成，在中央位置归还第一个值
    // key值左右分别递归

    if(left > start)
        quickSort(array, start, left - 1);
    if(right < end)
        quickSort(array, right + 1, end);
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
    quickSort(ranArray, 0, len - 1);
    end = clock();
    printf("排序完成，耗时:%dms\n", end - start);
    // 排序并计时

    free(ranArray); // 释放数组内存
    return 0;
}
