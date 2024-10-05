// 比较四个数的大小,其实把第一个比较两个数的放在一起就行了
#include <stdio.h>

int max(int num1, int num2){
    if(num1 < num2){
        return num2;
    }else{
        return num1;
    }
}

int main(){
    int a, b, c, d, maxNum;
    printf("请输入 4 个数:");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    maxNum = max(max(a, b), max(c, d));
    printf("最大的数是: %d", maxNum);
    return 0;
}