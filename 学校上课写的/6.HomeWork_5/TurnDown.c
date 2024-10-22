//4.9
#include <stdio.h>

int main(){
    long long num, mod, backup, i = 0, weight = 1;
    printf("请输入一个非负整数:");
    scanf("%llu", &num);
    backup = num;
    printf("逆序为:");
    do{
        mod = backup % 10;
        backup /= 10;
        i++;
        weight *= 10;
        printf("%llu", mod);
    }while(backup >= 1);
    weight /= 10;
    printf("\n它是一个%d位数", i);
    printf("\n各位数字分别为:");
    do{
        printf("%llu ", num / weight);
        num -= (num / weight) * weight;
        weight /= 10;
    }while(weight >= 1);
    printf("\n");
    return 0;
}