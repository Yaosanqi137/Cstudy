// test Q2
#include <stdio.h>

int perfectSquare[19] = {121, 144, 169, 196, 225, 256, 289, 324, 361, 441, 484, 529, 576, 625, 676, 729, 784, 841, 961};

int used[9] = {0};

void digit(int arr[3], int num, int card[9]){
    arr[2] = num / 100;
    arr[1] = (num - arr[2] * 100) / 10;
    arr[0] = num - arr[2] * 100 - arr[1] * 10;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 9; j++)
            if(card[j] == arr[i] && !used[j])
                used[j] = 1;
}

int check(int i, int j, int k, int card[9]){
    int num[3];
    for(int m = 0; m < 9; m++)
        used[m] = 0;
    digit(num, i, card);
    digit(num, j, card);
    digit(num, k, card);
    for(int m = 0; m < 9; m++)
        if(!used[m])
            return 1;
    return 0;
}

int haveSolve(int card[9]){
    for(int i = 0; i < 17; i++)
        for(int j = i + 1; j < 18; j++)
            for(int k = j + 1; k < 19; k++){
                if(!check(perfectSquare[i], perfectSquare[j], perfectSquare[k], card)){
                    printf("%d %d %d", perfectSquare[i], perfectSquare[j], perfectSquare[k]);
                    putchar('\n');
                    return 0;
                }
            }
    return 1;
}

int main(){
    int card[9];
    for(int i = 0; i < 9; i++)
        scanf("%d", &card[i]);
    if(haveSolve(card))
        printf("No");
    return 0;
}