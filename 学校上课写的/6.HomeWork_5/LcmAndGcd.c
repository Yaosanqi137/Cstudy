//5.3
#include <stdio.h>

void swap(int m, int n){ // 对换函数，保证gcd函数的输入数一定是前面大后面小
    if(m < n){
        int temp = m;
        m = n;
        n = temp;
    }
}

int gcd(int m, int n){ // 最大公因数
    int mod;
    swap(m, n);
    if(n == 0)
        return m;
    do{
        mod = m % n;
        if(mod == 0){
            return n;
        }else{
            m = n;
            n = mod;
        }
    }while(1);
}

int lcm(int m, int n){ // 最小公倍数
    if(m == 0 || n== 0)
        return 0;
    else
        return m * n / gcd(m, n);
}

int main(){
    int a, b;
    printf("请输入两个非负整数:");
    scanf("%d,%d", &a, &b);
    printf("最大公约数为%d\n", gcd(a, b));
    printf("最小公倍数为%d\n", lcm(a, b));
    return 0;
}
