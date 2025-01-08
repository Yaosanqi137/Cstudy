#include <stdio.h>
#include <stdlib.h>

int main(){
    int amount, j, check;
    scanf("%d", &amount);
    int *card = (int *)calloc(amount, sizeof(int));
    int *value = (int *)calloc(amount, sizeof(int));
    for(int i = 0; i < amount; i++)
        scanf("%d", &card[i]);
    for(int i = 0; i < amount; i++, j = 0, check = 0){
        while(value[j])
            if(value[j++] == card[i])
                check = 1;
        if(check)
            continue;
        value[j] = card[i];
        printf("%d ", card[i]);
    }
    free(card);
    free(value);
    return 0;
}