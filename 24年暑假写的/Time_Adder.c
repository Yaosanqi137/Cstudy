#include <stdio.h>

int main(){
    int TIME_1, TIME_2, TIME;
    printf("请输入现在的时间: ");
    scanf("%d", &TIME_1);
    printf("请输入你想加的时间: ");
    scanf("%d", &TIME_2);

    int HOUR_1 = TIME_1 / 100;
    int MIN_1 = TIME_1 - HOUR_1 * 100;
    int HOUR_2 = TIME_2 / 100;
    int MIN_2 = TIME_2 - HOUR_2*100;
    int MIN = MIN_2 + MIN_1;
    int HOUR = HOUR_1 + HOUR_2;

    if(MIN >= 60){
        HOUR = HOUR + MIN / 60;
        MIN = MIN % 60;
        if(HOUR * 100 + MIN > 2400){
            int DAY = HOUR / 24;
            HOUR = HOUR % 24;
            printf("现在是第 %d 天后的 %d 点 %d 分", DAY, HOUR, MIN);
            return 0;
        }else{
            printf("现在是 %d 点 %d 分", HOUR, MIN);
            return 0;
        }
    }else{
        if(HOUR * 100 + MIN > 2400){
            int DAY = HOUR / 24;
            HOUR = HOUR % 24;
            printf("现在是第 %d 天的 %d 点 %d 分", DAY, HOUR, MIN);
            return 0;
        }else{
            printf("现在是 %d 点 %d 分", HOUR, MIN);
            return 0;
        }
    }
    return 0;
}