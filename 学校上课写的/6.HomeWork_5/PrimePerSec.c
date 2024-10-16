#include <stdio.h>
#include <time.h>
#include <math.h>

int isPrime3(int n){
    if(n == 2)
        return 1;
    else if(n < 2 || n % 2 == 0)
        return 0;
    else
        for(int i = 3;i < sqrt(n) + 1;i += 2)
            if(n % i == 0)
                return 0;
    return 1;
}

int main(){
    int start, end, count = 0;
    start = clock();
    end = clock();
    for(int i = 1;end - start <= 1000;i++){
        if(isPrime3(i) == 1){
            count++;
        }
        end = clock();
    }
    printf("一共搜索到了%d个素数\n", count);
    printf("耗时:%dms", end - start);
}
