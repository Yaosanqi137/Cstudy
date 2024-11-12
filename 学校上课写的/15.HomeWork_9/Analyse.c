// Q1: 会输出1023
// Q2: 会输出3201
#include <stdio.h>

void numTos(int num, char s[]){
    static int i = 0;
    if(num){
        numTos(num / 10, s);
        s[i++] = num % 10 + '0';
    }
}

int main(){
    char str[12] = {0};
    int n;
    scanf("%d", &n);
    numTos(n, str);
    puts(str);
    return 0;
}