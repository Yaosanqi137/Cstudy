// 7.13
#include <stdio.h>
#include <stdlib.h>

double legendre(int n, double x, double arr[]){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(arr[n] != 0.0)
        return arr[n];
    arr[n] = ((2 * n - 1) * x * legendre(n - 1, x, arr) - (n - 1) * legendre(n - 2, x, arr)) / n;
    return arr[n];
}

int main(){
    int n;
    double x;
    printf("ÇëÊäÈën, x:");
    scanf("%d,%lf", &n, &x);
    double *lrd = (double *)calloc(n + 1, sizeof(double));
    printf("lrd=%lf\n", legendre(n, x, lrd));
    free(lrd);
    return 0;
}
