#include <stdio.h>
#include <stdlib.h>

struct date {
    short yyyy;
    short mm;
    short dd;
};

short isLeap(short yyyy){
    if((!(yyyy % 4) && yyyy % 100) || !(yyyy % 400))
        return 1;
    return 0;
}

void dateCal(struct date date){
    short totalDay = 0;
    while(1){
        if(date.mm <= 2 && date.dd < 29)
            totalDay += isLeap(date.yyyy) + 365;
        else if(date.mm == 2 && date.dd == 29)
            totalDay += 1461, date.yyyy += 3;
        else
            totalDay += isLeap(date.yyyy + 1) + 365;
        date.yyyy++;
        if(!(totalDay % 7))
            break;
    }
    printf("%hd\n", date.yyyy);
}

int main(){
    short amount;
    scanf("%hd", &amount);
    struct date *date = (struct date *)calloc(amount, sizeof(struct date));
    for(short i = 0; i < amount; i++)
        scanf("%hd-%hd-%hd", &date[i].yyyy, &date[i].mm, &date[i].dd);
    for(short i = 0; i < amount; i++)
        dateCal(date[i]);
    free(date);
    return 0;
}