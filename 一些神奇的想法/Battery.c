//小S 新买了一个掌上游戏机，这个游戏机由两节 5 号电池供电。
// 为了保证能够长时间玩游戏，他买了很多 5 号电池，这些电池的生产商不同，质量也有差异，因而使用寿命也有所不同，有的能使用 5 个小时，有的可能就只能使用 3 个小时。
// 显然如果他只有两个电池一个能用 5 小时一个能用 3 小时，那么他只能玩 3 个小时的游戏，有一个电池剩下的电量无法使用，但是如果他有更多的电池，就可以更加充分地利用它们，
// 比如他有三个电池分别能用 3、3 、5 小时，他可以先使用两节能用 3 个小时的电池，使用半个小时后再把其中一个换成能使用 5 个小时的电池，两个半小时后再把剩下的一节电池换成刚才换下的电池（那个电池还能用 2.5 个小时）
// ，这样总共就可以使用 5.5 个小时，没有一点浪费。
// 现在已知电池的数量和电池能够使用的时间，请你找一种方案使得使用时间尽可能的长。
#include <stdio.h>

int main(){
    int amount;
    double battery[128];
    double sum = 0, max = 0, time;
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++){
        scanf("%lf", &battery[i]);
        if(battery[i] > max)
            max = battery[i];
        sum += battery[i];
    }
    if(amount == 2){
        time = sum - max;
    }else if(amount > 2){
        sum -= max;
        if(sum > max)
            time = (sum + max) / 2;
        else
            time = sum;
    }else{
        time = 0;
    }
    printf("%.1lf", time);
    return 0;
}