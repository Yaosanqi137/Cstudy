#include <stdio.h>
#include <time.h>

int main(){
    long long a = 1,b = 0,c;
    int term, start, end;
    printf("请问你想看到斐波那契数列的第几项:");
    scanf("%d", &term);
    start = clock();
    for(int i = 1;i <= term;i++){
        printf("F[%d] = %lld\n", i, a);
        c = b;
        b = a;
        a += c;
    }
    end = clock();
    printf("耗时: %dms\n", end - start);
    return 0;
}