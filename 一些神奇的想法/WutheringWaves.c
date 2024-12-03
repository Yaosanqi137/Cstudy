#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 32 // 奖项名字最长字数
#define REWARDS 15 // 总奖项数量
#define UP 0 // up的人物
#define SMALL 10 // 小保底
#define BIG 80 // 大保底
#define MAX_TIME 160 // 一次性最多抽卡的次数
#define FIVE_STAR 6 // 5星的个数
#define FOUR_STAR 7 // 4星的个数
#define TRASH 14 // 三星装备

char REWARD[REWARDS][MAX_LEN] = {"椿", "卡卡罗", "安可", "雪豹", "鉴心", "高豪聪", "黄竣淘",
                                 "丹瑾", "秧秧", "四星装备1", "四星装备2", "四星装备3", "轻波级高豪聪", "轻波级黄竣淘",
                                 "杂鱼三星装备"};

int result[MAX_TIME];

int main(){
    srand(time(NULL));
    int goldenBalls, count_1 = 1, count_2 = 1, check = 0, isBIG = 0;
    double random;
    printf("你想要抽几发:");
    scanf("%d", &goldenBalls);
    for(int i = 0; i < goldenBalls; i++){
        if(count_2 == BIG && isBIG){
            result[i] = UP;
            count_2 = 1, check = 1, isBIG = 0;
        }else if(count_2 == BIG){
            result[i] = rand() % (FIVE_STAR + 1);
            check = 1, isBIG = 1, count_2 = 1;
        }
        else if(count_1 == SMALL){
            result[i] = FIVE_STAR + 1 + rand() % FOUR_STAR;
            check = 1, count_1 = 1, count_2++;
        }
        // 保底计算
        if(check){
            check = 0;
            continue;
        }
        // 若已经进行保底计算，则结束本次循环
        random = rand() % 1000 / 1000.0;
        if(count_2 >= 70)
            random += (count_2 - 69) * 0.001;
        if(random <= 0.932){
            result[i] = TRASH;
            count_1++, count_2++;
        }else if(random <= 0.992){
            result[i] = FIVE_STAR + 1 + rand() % FOUR_STAR;
            count_1 = 1, count_2++;
        }else{
            result[i] = rand() % (FIVE_STAR + 1), count_1++;
            if(result[i] == UP)
                count_2 = 1, isBIG = 0;
            else if(isBIG){
                result[i] = UP;
                count_2++, isBIG = 0;
            }else if(result[i] != UP)
                count_2 = 1, isBIG = 1;
        }
        // 普通抽卡计算
    }
    for(int i = 0; i < goldenBalls; i++)
        printf("第%d抽: %s\n", i + 1, REWARD[result[i]]);
    printf("\n其中出了4星及以上奖励的抽数为:\n\n");
    for(int i = 0; i < goldenBalls; i++)
        if(result[i] < FOUR_STAR + FIVE_STAR + 1)
            printf("第%d抽: %s\n", i + 1, REWARD[result[i]]);
    printf("\n其中出了5星及以上奖励的抽数为:\n\n");
    for(int i = 0; i < goldenBalls; i++)
        if(result[i] < FIVE_STAR + 1)
            printf("第%d抽: %s\n", i + 1, REWARD[result[i]]);
    return 0;
}