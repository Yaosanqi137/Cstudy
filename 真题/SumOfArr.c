#include <stdio.h>

int main(){
    int b = 1, a = 1, n, i;
    double sum = 0;
    scanf("%d", &n);
    for(i = 0; sum < n; i++){
        sum += b / (double)a;
        a += b;
        b += a;
    }
    printf("Items:%d", i);
    return 0;
}