// test Q3
#include <stdio.h>

int amount(int n){
    int total, sum = 0;
    for(int i = 0; n >= 3; i++, n--){
        total = 1;
        for(int j = 10; j >= 10 - i; j--){
            total *= j;
            total += ;
        }
        sum += total;
    }
    return sum;
}

int main(){
    int n, total;
    scanf("%d", &n);
    total = amount(n);
    printf("%d\n", total);
    return 0;
}