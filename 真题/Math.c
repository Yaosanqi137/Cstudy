// 2021 C
#include <stdio.h>
#define N 10

void analyse(int min[N], int max[N]){
    int result = 0, i = 0;
    while(max[i]){
        for(int c = min[i]; c <= max[i]; c++){
            for(int a = min[i]; a <= c; a++)
                for(int b = min[i]; b <= c - a; b++)
                    if(a*a*a + b*b*b > c * 10 +3) break;
                    else if(a*a*a + b*b*b == c * 10 +3) result++;
        }
        printf("Case %d: %d\n", i + 1, result);
        i++;
    }
}

int main(){
    int min[N] = {0}, max[N] = {0}, i = 0;
    while(scanf("%d %d", &min[i], &max[i]))
        i++;
    analyse(min, max);
    return 0;
}