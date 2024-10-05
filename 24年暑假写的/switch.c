#include <stdio.h>

int main(){
    int level;
    scanf("%d", &level);

    switch (level){
    case 100:
        printf("nb");
        break;
    case 80:
        printf("还可以");
        break;
    case 60:
        printf("傻逼");
        break;
    case 40:
        printf("史");
        break;
    default:
        printf("你输入了个什么屎?");
        break;
    }

    int a = 58;
    if( a > 50 ) printf("A");
    if( a > 40 ) printf("B");
    if( a > 30 ) printf("C");

    return 0;
}