#include <stdio.h>
#define N 8 // 这里可以是任何数

int main(){
    int a, mx;
    printf("请输入%d个数字: ", N);
    scanf("%d", &a);
    mx = a;
    for(int i = 2;i <= N;i++){
        scanf("%d", &a);
        if(a >= mx)
            mx = a;
    }
    printf("最大的数字是: %d\n", mx);
    return 0;
}