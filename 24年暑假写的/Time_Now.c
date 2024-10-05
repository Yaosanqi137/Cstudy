#include <stdio.h>

int main(){
    error:
    printf("请输入4位时间:");
    int TIME;
    scanf("%d", &TIME);
    if(TIME > 2400){
        printf("你家一天有24个小时以上?重新来!\n");
        goto error;
    }
    int HOUR = TIME/100;
    int MIN = TIME - HOUR*100;
    if(HOUR <= 24 && MIN <=60){
        if(HOUR < 13){
            printf("现在是:上午%d点%d分.", HOUR, MIN);
        }else if(HOUR < 18){
            HOUR -= 12;
            printf("现在是:下午%d点%d分.", HOUR, MIN);
        }else if(HOUR < 23){
            HOUR -= 12;
            printf("现在是:晚上%d点%d分.", HOUR, MIN);
        }else{
            HOUR -= 12;
            printf("现在是:午夜%d点%d分.", HOUR, MIN);
        }
    }else{
        printf("你输入了个什么东西?重新来!\n");
        goto error;
    }
}
