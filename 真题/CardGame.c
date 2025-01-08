#include <stdio.h>

int num[100] = {0}, result[256] = {0};
int head = 128, tail = 128;

void toNum(char str[100]){
    for(int i = 0; str[i]; i++)
        num[i] = str[i] - 47;
}

void placeCard(){
    int i = 1;
    while(num[i])
        if((num[i] - 1) > result[head] || !(num[i] - 1))
            result[++tail] = num[i++] - 1;
        else
            result[--head] = num[i++] - 1;
}

int main(){
    char nums[100];
    scanf("%s", nums);
    toNum(nums);
    result[128] = num[0] - 1;
    placeCard();
    for(int i = head; i <= tail; i++){
        printf("%d", result[i]);
    }
    return 0;
}