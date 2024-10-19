//写一个程序，使其能够根据输入的成绩打印出等级，通过输入等级显示
//所有已输入的该等级的成绩。(成绩取整数，0-59为'D’,60-79为'C’，
//80-89为'B’，90-100 为'A’，每个等级最多有十个成绩)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char studentMark[161];
    int a = 0, b = 0, c = 0, d = 0, temp, A[10], B[10], C[10], D[10];
    const char WALL[1] = " ";
    printf("请逐个输入学生的成绩:");
    fgets(studentMark, 162, stdin);
    // 初始化变量 输入信息
    temp = atoi(strtok(studentMark, WALL));
    while(temp != NULL){
        if(temp < 60){
            D[d] = temp;
            d++;
        }else if(temp < 80){
            C[c] = temp;
            c++;
        }else if(temp < 90){
            B[b] = temp;
            b++;
        }else if(temp <= 100){
            A[a] = temp;
            a++;
        }
        temp = atoi(strtok(NULL, WALL));
    }
    // 信息处理
    printf("请看成绩表\nA: ");
    for(int i = 0;i < a;i++){
        printf("%d ", A[i]);
    }
    printf("\nB: ");
    for(int i = 0;i < b;i++){
        printf("%d ", B[i]);
    }
    printf("\nC: ");
    for(int i = 0;i < c;i++){
        printf("%d ", C[i]);
    }
    printf("\nD: ");
    for(int i = 0;i < d;i++){
        printf("%d ", D[i]);
    }
    printf("\n");
    // 输出数据
    return 0;
    // 退出程序
}