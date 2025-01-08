#include <stdio.h>

char checkID[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2', '1'};
int num[17] = {7, 9,10, 5, 8, 4, 2, 1,6, 3, 7, 9, 10, 5, 8, 4, 2};

int check(char id[18]){
    int sum = 0;
    for(int i = 0; i < 17; i++)
        sum += (id[i] - 48) * num[i];
    if(checkID[(sum % 11)] == id[17])
        return 1;
    else
        return 0;
}

int main(){
    char id[19];
    int valid;
    scanf("%s", id);
    valid = check(id);
    if(valid)
        printf("OK");
    else
        printf("ERROR");
    return 0;
}