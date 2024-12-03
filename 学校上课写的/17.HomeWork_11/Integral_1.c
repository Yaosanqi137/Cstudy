// 8.13
#include <stdio.h>
#include <math.h>
#define N 1e7

double f1(double x){
    return sin(x);
}

double f2(double x){
    return cos(x);
}

double f3(double x){
    return exp(x) + 1;
}

void printMenu(){
    printf("1.sin(x) 2.cos(x) 3.exp(x)+1 0.exit\n");
    printf("请选择:");
}

double integral(double a, double b, double (*func)(double)){
    double h = (b - a) / N, sum = 0;
    for(int i = 0; i <= N; i++)
        sum += (*func)(a + i * h) * h;
    return sum;
}

int main(){
    double (*func)(double), a, b, result;
    int mode;
    do{
        printMenu();
        scanf("%d", &mode);
        switch(mode){
            case 1:
                func = f1;
                break;
            case 2:
                func = f2;
                break;
            case 3:
                func = f3;
                break;
            case 0:
                return 0;
        }
        printf("请输入积分下限和上限:");
        scanf("%lf,%lf", &a, &b);
        if(a < b)
            result = integral(a, b, func);
        else if(a > b)
            result = -integral(b, a, func);
        else if((a - b) < 1e-5)
            result = 0;
        printf("result = %lf\n\n", result);
    }while(mode != 4);
}
