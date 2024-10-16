// 5.14
#include <stdio.h>

double f(double x){
    return 2*(x*x*x) - 4*(x*x) + 3*x - 6;
}

double f1(double x){
    return 6*(x*x) - 8*x + 3;
}

double binIteration(double left, double right){ // 原理看书
    if(f(left) * f(right) < 0){
        double mid;
        do{
            mid = (left + right) / 2;
            if(f(mid) > 0){
                right = mid;
            }else if(f(mid) < 0){
                left = mid;
            }else{
                return mid;
            }
        }while(right - left > 1e-7);
        return mid;
    }else{
        return 1;
    }
}

int main(){
    double result = binIteration(-10, 10);
    printf("root= %lf\n", result);
}