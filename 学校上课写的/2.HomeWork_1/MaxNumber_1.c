// yysy，牢李（我老师）是真的阴间，一上来就给新手上函数声明了
#include <stdio.h>

int max3(int num1, int num2, int num3){
    if(num1 <= num2){
        if(num2 <= num3)
            return num3;
        else
            return num2;
    }else{
        if(num1 <= num3)
            return num3;
        else
            return num1;
    }
}

int main() {
    int a, b, c, maxNum;
    printf("请输入3个数(格式为111 123 321):\n");
    scanf("%d %d %d", &a, &b, &c);
    maxNum = max3(a, b, c);
    printf("三者中最大的数是:\n%d", maxNum);
    return 0;
}