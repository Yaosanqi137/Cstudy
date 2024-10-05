// 检测输入的坐标在不在4个圆里面
#include <stdio.h>

double square(double n){
    return n * n;
}

int circlePosition(double x, double y){
    if(square(2 - x) + square(2 - y) <= 1)
        return 10;
    else if(square(2 - x) + square(-2 - y) <= 1)
        return 10;
    else if(square(-2 - x) + square(2 - y) <= 1)
        return 10;
    else if(square(-2 - x) + square(-2 - y) <= 1)
        return 10;
    else
        return 0;
}

int main(){
    double x, y;
    printf("请输入一个坐标:");
    scanf("%lf,%lf", &x, &y);
    printf("h = %dm\n", circlePosition(x, y));
}