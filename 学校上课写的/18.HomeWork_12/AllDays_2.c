// 9.13
#include <stdio.h>

int months[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int year[2] = {365, 366};
int isLeap;

struct date {
    int yyyy, mm, dd;
};

int isLeapYear(int yyyy){
    if(!(yyyy % 4) && (yyyy % 100) || !(yyyy % 400))
        return 1;
    return 0;
}

struct date allDays(struct date begin, int days){
    isLeap = isLeapYear(begin.mm > 2 ? begin.yyyy + 1 : begin.yyyy);
    while(days >= year[isLeap]){
        days -= year[isLeap];
        begin.yyyy++;
        isLeap = isLeapYear(begin.mm > 2 ? begin.yyyy + 1 : begin.yyyy);
    }
    isLeap = isLeapYear(begin.yyyy);
    while(days >= months[isLeap][begin.mm - 1]){
        days -= months[isLeap][begin.mm - 1];
        begin.mm++;
        if(begin.mm == 13){
            begin.mm = 1;
            begin.yyyy++;
            isLeap = isLeapYear(begin.yyyy);
        }
    }
    begin.dd += days;
    while(begin.dd > months[isLeap][begin.mm - 1]){
        begin.dd -= months[isLeap][begin.mm - 1];
        begin.mm++;
        if(begin.mm == 13){
            begin.mm = 1;
            begin.yyyy++;
        }
    }
    return begin;
}

int main(){
    struct date date;
    int days;
    printf("请输入初始日期:");
    scanf("%d-%d-%d", &date.yyyy, &date.mm, &date.dd);
    printf("间隔天数:");
    scanf("%d", &days);
    date = allDays(date, days);
    printf("终止日期为:%d-%02d-%02d\n", date.yyyy, date.mm, date.dd);
    return 0;
}