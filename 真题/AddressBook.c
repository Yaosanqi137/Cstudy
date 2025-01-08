#include <stdio.h>
#include <stdlib.h>

struct info {
    char name[11];
    int birthday;
    char phone[18];
};

struct info temp;

void exchange(struct info *info1, struct info *info2){
    temp = *info1;
    *info1 = *info2;
    *info2 = temp;
}

void sort(struct info arr[], short len){
    for(short i = 0; i < len - 1; i++)
        for(short j = 0; j < len - i - 1; j++)
            if(arr[j].birthday > arr[j + 1].birthday)
                exchange(&arr[j + 1], &arr[j]);
}

int main(){
    short amount;
    scanf("%hd", &amount);
    struct info *info = (struct info *)calloc(amount, sizeof(struct info));
    for(short i = 0; i < amount; i++)
        scanf("%s %d %s", info[i].name, &info[i].birthday, info[i].phone);
    sort(info, amount);
    for(short i = 0; i < amount; i++)
        printf("%s %d %s\n", info[i].name, info[i].birthday, info[i].phone);
    free(info);
    return 0;
}