// 7.13
#include <stdio.h>

double legendre(int n, double x){
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    double p0 = 1;
    double p1 = x;
    double pn;
    for(int i = 2; i <= n; i++){
        pn = ((2 * i - 1) * x * p1 - (i - 1) * p0) / i;
        p0 = p1;
        p1 = pn;
    }
    return pn;
}

int main(){
    int n;
    double x;
    printf("ÇëÊäÈën, x:");
    scanf("%d,%lf", &n, &x);
    printf("lrd=%lf\n", legendre(n, x));
}
