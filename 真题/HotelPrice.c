#include <stdio.h>

int arr[32][3];

int merge(int dateRangePrices[][3], int n){
    int day[512] = {0};
    int count = 1, N = 0;
    for(int i = 0; i < n; i++)
        for(int j = dateRangePrices[i][0]; j <= dateRangePrices[i][1]; j++)
            day[j] = dateRangePrices[i][2];
    while(1)
        if(!day[count]) break;
        else if(count == 1 || day[count - 1] != day[count] && count - 1){
            arr[++N][0] = count;
            arr[N][1] = count;
            arr[N][2] = day[++count];
        }else arr[N][1] = count++;
    return N;
}

int main(){
    int n;
    scanf("%d", &n);
    int array[32][3];
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &array[i][0], &array[i][1], &array[i][2]);
    n = merge(array, n);
    for(int i = 1; i <= n; i++){
        printf("[%d, %d, %d]", arr[i][0], arr[i][1], arr[i][2]);
        if(arr[i + 1][0])
            putchar(',');
    }
    return 0;
}