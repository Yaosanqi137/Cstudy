//好弱智的程序
#include <stdio.h>
#define PI 3.1415926

int main(){
    double radius, height;
    printf("请输入半径和高:");
    scanf("%lf,%lf",&radius, &height);

    printf("圆的周长是: %.2lf\n", radius * 2 * PI);
    printf("圆的面积是: %.2lf\n", radius * radius * PI);
    printf("球的表面积: %.2lf\n", radius * 4 * PI);
    printf("球的体积: %.2lf\n", 4.0 * (radius *radius * radius) * PI / 3);
    printf("圆柱的体积: %.2lf\n", radius * 2 * PI * height);
}