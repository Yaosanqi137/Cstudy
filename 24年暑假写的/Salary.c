#include <stdio.h>

int main(){
    printf("请输入利润总数(单位:万):");
    double I;
    scanf("%lf", &I);
    getchar();
    double Salary;
    if(I <= 10){
        Salary = I*0.1;
    }else if(I <= 20){
        Salary = 1 + (I - 10)*0.075;
    }else if(I <= 40){
        Salary = 1.75 + (I - 20)/20.0;
    }else if(I <= 60){
        Salary = 2.25 + (I - 40)*0.03;
    }else if(I <= 100){
        Salary = 2.85 + (I - 60)*0.015;
    }else if(I > 100){
        Salary = 3.45 + (I - 100)/100.0;
    }
    printf("你的提成为: %f", Salary);
}