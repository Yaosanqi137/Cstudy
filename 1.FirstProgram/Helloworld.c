/*
#include <stdio.h>

int main(){
    printf("HelloWorld");
    return 0;
}

我去，不会真有人现在还在把 HelloWorld 当自己的第一个程序吧!?
 */

#include <stdio.h>

int max(int num1, int num2){ // 比较大小函数
    if(num1 <= num2)
        return num2;
    else
        return num1;
}

int main(){
    int a, b, maxNum;
    printf("请输入俩个数来比大小(格式: 123 321): \n");
    scanf("%d %d", &a, &b);
    getchar();
    maxNum = max(a, b);
    printf("最大的数字是: %d\n", maxNum);
    return 0;
}