#include <stdio.h>

int main(){
    int foot,inch;
    printf("请输入你几尺:");
    scanf("%d", &foot);
    printf("请输入你几寸:");
    scanf("%d", &inch);
    float height = (foot + inch/12.0)*0.3048;
    printf("你的身高是:%f cm", height);
}