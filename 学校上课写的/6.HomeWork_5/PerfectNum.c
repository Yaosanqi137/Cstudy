// 5.9
#include <stdio.h>
#include <time.h>

int factorSum(int num){
    int sum = 1;
    for(int i = 2;i * i <= num;i += 2)
        if(num % i == 0){
            sum += i;
            if(i != num / i)
                sum += num / i;
        }
    return sum;
}

int main(){
    int n, start, end;
    printf("type in a number:");
    scanf("%d", &n);
    printf("its factors are:");
    start = clock();
    for(int j = 1;j <= n;j++)
        if(j == factorSum(j))
            printf("%d ", j);
    end = clock();
    printf("\ntime:%dms\n", end - start);
    return 0;
}