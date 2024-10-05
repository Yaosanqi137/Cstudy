#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Bubble(int arr[], int arrLength){ // 普普通通的冒泡排序罢了
    int TEMP;
    for(int n = 0;n < arrLength - 1;n++){
        if(arr[n + 1] < arr[n]){
            TEMP = arr[n + 1];
            arr[n + 1] = arr[n];
            arr[n] = TEMP;
        }
    }
}

int Dichotomy(int arr[], int arrLength, int target){ // 普普通通的二分法罢了
    int right = arrLength - 1;
    int left = 0;
    int mid;
    while(1){
        mid = (right + left) / 2;
        if(arr[mid] > target){
            right = mid - 1;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            break;
        }
    }
    return mid;
}

int sum(int arr[], int length){
    int sum = 0;
    for(int n = 0;n < length;n++){
        sum += arr[n];
    }
    return sum;
}

int main(){
    srand(time(NULL)); // 设置随机数生成种子
    int length, testTime, startTime, endTime, targetPosition, maxTime, minTime;

    printf("请输入你想要生成的随机数组长度");
    scanf("%d", &length);
    printf("请输入你想要测试的次数");
    scanf("%d", &testTime);

    int *ranArray = malloc(length * 8); // 分配动态数组内存
    int *timeArray = malloc(testTime * 8);

    for(int runTime = 0;runTime < testTime;runTime++){
        for(int ELEMENT = 0;ELEMENT < length;ELEMENT++){
            ranArray[ELEMENT] = rand() % 10000;
        }
        // 创建指定长度的随机数组

        startTime = clock();
        Bubble(ranArray, length);
        targetPosition = Dichotomy(ranArray, length, rand() % 10000);
        endTime = clock();

        timeArray[runTime] = endTime - startTime;
        printf("第 %d 次测试完成，耗时 %d ms, 目标数字位于第 %d 位", runTime + 1, timeArray[runTime], targetPosition);
    }

    Bubble(timeArray, testTime);
    maxTime = timeArray[testTime - 1];
    minTime = timeArray[0];
    printf("测试完成，本次测试最大耗时 %d ms, 最小耗时 %d ms, 平均耗时 %d ms", maxTime, minTime, sum(timeArray, testTime) / testTime);

    free(ranArray); // 释放数组内存
    free(timeArray);
    return 0;
}