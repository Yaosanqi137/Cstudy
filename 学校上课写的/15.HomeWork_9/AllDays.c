// 7.18
#include <stdio.h>

int months[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

int isLeapYear(int yyyy){
    if(yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy  % 4 == 0))
        return 1;
    else
        return 0;
}

int allDays(int sy, int sm, int sd, int ty, int tm, int td){
    int total = 0;
    if(sy == ty && sm == tm)
        return td - sd;
    for(int yyyy = sy + 1; yyyy < ty; yyyy++)
        total += isLeapYear(yyyy) ? 366 : 365;
    for(int mm = sm + 1; mm <= (sy == ty ? tm - 1 : 12); mm++)
        total += months[isLeapYear(sy)][mm - 1];
    for(int mm = 1; mm < (sy == ty ? 1 : tm); mm++)
        total += months[isLeapYear(ty)][mm - 1];
    total += (months[isLeapYear(sy)][sm - 1] - sd + 1) + td;
    return total - 1;
}

int main(){
    int sy, sm, sd, ty, tm, td;
    printf("请输入起始日期:");
    scanf("%d-%d-%d", &sy, &sm, &sd);
    printf("请输入终止日期:");
    scanf("%d-%d-%d", &ty, &tm, &td);
    printf("dis=%d天.\n", allDays(sy, sm, sd, ty, tm, td));
    return 0;
}
