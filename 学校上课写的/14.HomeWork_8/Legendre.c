// 7.13
#include <stdio.h>

double legendre(int n, double x){
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if(n > 1)
        return ((2 * n - 1) * x * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / n;
    else
        return -1; // error
}

int main(){
    int n;
    double x;
    printf("ÇëÊäÈën, x:");
    scanf("%d,%lf", &n, &x);
    printf("lrd=%lf\n", legendre(n, x));
    return 0;
}
