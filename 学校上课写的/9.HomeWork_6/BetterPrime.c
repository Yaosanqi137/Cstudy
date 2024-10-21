// 6.1
#include <stdio.h>
#include <time.h>
#define N 100000000

int arr[N + 1];

int main(){
    int i, j, end, start,count = 0;
    start = clock();
    for(i = 3;i * i <= N;i += 2){
        if(!arr[i])
            for(j = i * i;j <= N;j += 2 * i)
                if(!arr[j])
                    arr[j] = 1;
    }
    end = clock();
    count = (N >= 2) ? 1 : 0;
    for(i = 3;i <= N;i += 2)
        if(!arr[i])
            count++;
    printf("100000000以内的素数有: %d个\n", count);
    printf("耗时: %dms\n", end - start);
    return 0;
}
