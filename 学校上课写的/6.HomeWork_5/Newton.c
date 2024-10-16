// 5.14
#include <stdio.h>
#include <math.h>

double f(double x){
    return 2*(x*x*x) - 4*(x*x) + 3*x - 6;
}

double f1(double x){
    return 6*(x*x) - 8*x + 3;
}

double Newton(double x0){ // 原理看书
    double x, temp;
    do{
        x = x0 - f(x0)/f1(x0);
        temp = x0;
        x0 = x;
    }while(fabs(x - temp) >= 1e-7);
    return x;
}

int main(){
    double start, end;
    double result = Newton(1.5);
    printf("root=%lf\n", result);
}