// 9.14
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_SALES 1000
#define MAX_SALES 5000
#define N 4

struct data {
    char name[20];
    int sales[13]; // 规定 sales[0] 为年销量
};

void monthSort(struct data *p[], int n, int m){
    struct data *temp;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(p[j]->sales[m] < p[j + 1]->sales[m]){
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
}

void printM(struct data *p[], int n, int m){
    for(int i = 0; i < n; i++)
        printf("%-6d %-8s %-8d\n", i + 1, p[i]->name, p[i]->sales[m]);
}

void printAll(struct data mobile[], int n){
    for(int i = 0; i < n; i++){
        printf("%-2d %-6s", i + 1, mobile[i].name);
        for(int j = 1; j < 12; j++)
            printf("%8d", mobile[i].sales[j]);
        printf("%8d\n", mobile[i].sales[0]);
    }
}

void createData(struct data mobile[], int n){
    for(int i = 0; i < n; i++)
        for(int j = 1; j <= 12; j++){
            mobile[i].sales[j] = MIN_SALES + rand() % (MAX_SALES - MIN_SALES + 1);
            mobile[i].sales[0] += mobile[i].sales[j];
        }
}

int main(){
    int i, m;
    srand(time(NULL));
    struct data *p[N], mobile[N] = {{"HUAWEI"}, {"VIVO"}, {"XIAOMI"}, {"OPPO"}};
    createData(mobile, N);
    printAll(mobile, N);
    for(i = 0; i < N; i++)
        p[i] = &mobile[i];
    printf("\nPlease input m(-1<=m<=12, -1 for exit):");
    scanf("%d", &m);
    while(m >= 0 && m <= 12){
        monthSort(p, N, m);
        printM(p, N, m);
        printf("\nPlease input m(-1<=m<=12, -1 for exit):");
        scanf("%d", &m);
    }
    return 0;
}
