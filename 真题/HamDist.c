#include <stdio.h>

int main(){
    int num1, num2, result, count = 0;
    scanf("%d %d", &num1, &num2);
    result = num1 ^ num2;
    while(1){
        1 == (result % 2) ? count++ : count;
        result /= 2;
        if(!result)
            break;
    }
    printf("%d", count);
    return 0;
}