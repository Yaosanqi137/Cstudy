#include <stdio.h>

int fun(int a, int b){
    return (a % 10) * 1000 + (a / 10) * 10 + (b / 10) * 100 + b % 10;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", fun(a, b));
    return 0;
}