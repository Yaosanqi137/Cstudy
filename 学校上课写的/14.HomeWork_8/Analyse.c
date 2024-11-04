// 回旋矩阵，data[0][0] = N * N
#include <stdio.h>

int main(){
    int i, j, k, N, count;
    int data[20][20] = {0};
    printf("Input an integer N:");
    scanf("%d", &N);
    count = N * N;
    for(k = 0; k < N; k++){
        for(i = k; i < N - k; i++)
            data[k][i] = count--;
        for(i = k + 1; i < N - k; i++)
            data[i][N - k - 1] = count--;
        for(i = N - k - 2; i > k; i--)
            data[N - k - 1][i] = count --;
        for(i = N - k - 1; i > k; i--)
            data[i][k] = count--;
    }
    if(N % 2 != 0)
        data[N / 2][N / 2] = 1;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%4d", data[i][j]);
        printf("\n");
    }
    return 0;
}
