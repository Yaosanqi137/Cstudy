// 6.8
#include <stdio.h>

int main(){
    int doubleArr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++)
            printf("%d ", doubleArr[i][j]);
        printf("\n");
    }
//    for(int i = 0; i < 3; i++)
//        for(int j = 0; j < 4; j++)
//            scanf("%d", &doubleArr[i][j]);
    // 生成判断数列
    int checkCol[3][4] = {0};
    int checkRow[3][4] = {0};
    // 每行判断最大
    for(int i = 0; i < 3; i++){
        int key = 0;
        for(int k = 0; k < 4; k++){
            if (doubleArr[i][k] > doubleArr[i][key])
                key = k;
        }
        checkCol[i][key]++;
    }
    // 每列判断最小
    for(int i = 0; i < 4; i++){
        int key = 0;
        for(int k = 0; k < 3; k++){
            if(doubleArr[k][i] < doubleArr[key][i])
                key = k;
        }
        checkRow[key][i]++;
    }
    // 输出
    int check = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
            if(checkCol[i][j] && checkRow[i][j]){
                printf("鞍点为%d，在第%d行第%d列上\n", doubleArr[i][j], i + 1, j + 1);
                check = 1;
            }
    if(!check)
        printf("无鞍点\n");
    return 0;
}
