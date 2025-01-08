#include <stdio.h>

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int year){
    if(!(year % 400) || (year % 100) && !(year % 4))
        return 1;
    return 0;
}

int totalDays(int yyyy, int mm, int dd){
    int days = 0;
    for(int i = 1700; i < yyyy; i++)
        days += 365 + isLeap(i);
    for(int i = 0; i < mm - 1; i++)
        days += month[i] + isLeap(yyyy);
    days += dd;
    return days;
}

int main(){
    int yyyy, mm, dd, result;
    scanf("%d-%d-%d", &yyyy, &mm, &dd);
    result = totalDays(yyyy, mm, dd) % 5;
    switch(result){
        case 0:
            printf("D2");
            break;
        case 1:
            printf("F1");
            break;
        case 2:
            printf("F2");
            break;
        case 3:
            printf("F3");
            break;
        case 4:
            printf("D1");
            break;
    }
    return 0;
}