#include <stdio.h>
#define QUEEN 4

int solutions;
int placed[QUEEN][QUEEN];
int placedX[QUEEN];
int placedDiagLeft[QUEEN * 2];
int placedDiagRight[QUEEN * 2];

void print(){ // 输出
    solutions++;
    for(int i = 0; i < QUEEN; i++){
        for(int j = 0; j < QUEEN; j++)
            printf("%3d", placed[i][j]);
        printf("\n");
    }
    printf("\n");
}

void NQueen(int queen){
    if(queen == QUEEN){ // 说明放完了，可以输出了
        print();
        return;
    }
    for(int x = 0; x < QUEEN; x++){
        if(!placedX[x] && !placedDiagLeft[queen - x + QUEEN] && !placedDiagRight[queen + x]){ // 对于直线来说y - kx = C，用y - kx即可作为对角线的标记，同时queen - x再加queen是为了索引不小于0
            placed[queen][x] = 1; // 标记列和两个对角线
            placedX[x] = 1;
            placedDiagRight[queen + x] = 1;
            placedDiagLeft[queen - x + QUEEN] = 1;
            NQueen(queen + 1); // 皇后放置完成，放下一个
            placed[queen][x] = 0; // 回溯
            placedX[x] = 0;
            placedDiagRight[queen + x] = 0;
            placedDiagLeft[queen - x + QUEEN] = 0;
        }
    }
}

int main(){
    NQueen(0);
    printf("一共有%d种解法\n", solutions);
    return 0;
}