#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GCD(int a, int b){
    int mod = 1;
    while(mod){
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

void process(int a1, int b1, int a2, int b2){
    int b = b1 * b2, a = a1 * b2 + a2 * b1, gcd;
    gcd = GCD(a, b);
    b /= gcd;
    a /= gcd;
    if(b == 1)
        printf("%d", a);
    else
        printf("%d/%d", a, b);
}

int main(){
    char num1[20], num2[20];
    int a1, b1 = 1, a2, b2 = 1;
    scanf("%s %s", num1, num2);
    if(strstr(num1, "/") != NULL)
        sscanf(num1, "%d/%d", &a1, &b1);
    else
        a1 = atoi(num1);
    if(strstr(num2, "/") != NULL)
        sscanf(num2, "%d/%d", &a2, &b2);
    else
        a2 = atoi(num2);
    process(a1, b1, a2, b2);
    return 0;
}