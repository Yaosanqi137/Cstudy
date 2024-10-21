// 5.16
#include <stdio.h>

int main(){
    int n;
    printf("请输入整数n(1 <= n <= 20):");
    scanf("%d", &n);
    if(n < 1 || n > 20){
        printf("错误输入\n");
        return 1;
    }
    for(int i = 1;i <= n;i++) {
        for (int j = 1; j <= n - i; j++)
            putchar(' ');
        for (int k = 1; k <= i * 2 - 1; k++)
            putchar('*');
        putchar('\n');
    }
    for(int i = n - 1;1 <= i;i--) {
        for (int j = 1; j <= n - i; j++)
            putchar(' ');
        for (int k = 1; k <= i * 2 - 1; k++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}