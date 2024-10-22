// 5.9
#include <stdio.h>
#include <time.h>

void factors(int num){
    int i = 1;
    do{
        if (num % i == 0)
            printf("%d ", i);
        i++;
    } while (i < num);
}

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
    int n, start, end, count = 0;
    printf("type in a number:");
    scanf("%d", &n);
    start = clock();
    for(int j = 1;j <= n;j++)
        if(j == factorSum(j)){
            printf("%d its factors are: ", j);
            factors(j);
            putchar('\n');
            count++;
        }
    printf("there are %d perfect numbers in total within %d", count, n);
    end = clock();
    printf("\ntime:%dms\n", end - start);
    return 0;
}