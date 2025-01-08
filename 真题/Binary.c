// test Q1
#include <stdio.h>

short bin[31];

int main(){
    int num, count = 0;
    scanf("%d", &num);
    while(1){
        bin[count++] = num % 2;
        num /= 2;
        if(num == 1 || !num){
            bin[count] = num;
            break;
        }
    }
    printf("%d ", count + 1);
    for(int i = count; i >= 0; i--)
        printf("%hd", bin[i]);
    return 0;
}