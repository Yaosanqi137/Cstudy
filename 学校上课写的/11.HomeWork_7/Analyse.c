// 分析程序
#include <stdio.h>
#include <stdlib.h>

void process(int b[10][10], int m){
    int i = 0, j = m/ 2, k;
    b[i][j] = 1;
    for(k = 2; k <= m * m; k++){
        i--; j++;
        if((i < 0) && (j >= m)){
            i += 2; j--;
        }
        if(i < 0)
            i = m - 1;
        if(j >= m)
            j = 0;
        if(b[i][i] != 0){
            i += 2; j--;
        }
        b[i][j] = k;
    }
}

int main(){
    int i, j, n;
    int a[10][10] = {0};
    printf("Input n:");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("%d * %d matrix is illegal. \n", n, n);
        exit(0);
    }else
        process(a, n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}