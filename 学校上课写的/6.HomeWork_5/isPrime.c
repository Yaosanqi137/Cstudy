// 测试一下哪个素数查找算法最好
#include <stdio.h>
#include <time.h>
#include <math.h>

int isPrime1(int n){ // 1.逐个查找
    if(n < 2)
        return 0;
    for(int i = 2;i < n;i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int isPrime2(int n){ // 2.仅查找到目标数的开方
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    else
        for(int i = 2;i < sqrt(n) + 1;i++)
            if(n % i == 0)
                return 0;
    return 1;
}

int isPrime3(int n){ // 3.除了2以外的素数必为奇数，所以仅检测偶数，同样仅查找到目标数的开方，目前最好的方法
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
    int start, end, term = 1000000, count = 0;
    start = clock();
    for(int i = 1;i <= term;i++){ // 这个算法真的很烂，建议不要测试
        if(isPrime1(i) == 1){
            count++;
        }
    }
    printf("一共有%d个素数\n", count);
    end = clock();
    count = 0;
    printf("耗时:%dms\n", end - start);
    start = clock();
    for(int i = 1;i <= term;i++){
        if(isPrime2(i) == 1){
            count++;
        }
    }
    printf("一共有%d个素数\n", count);
    end = clock();
    count = 0;
    printf("耗时:%dms\n", end - start);
    start = clock();
    for(int i = 1;i <= term;i++){
        if(isPrime3(i) == 1){
            count++;
        }
    }
    printf("一共有%d个素数\n", count);
    end = clock();
    printf("耗时:%dms\n", end - start);
}