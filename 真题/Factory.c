#include <stdio.h>

int material[4];

int min(int arr[4]){
    int min = 100;
    for(int i = 0; i < 4; i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

void P1(){
    int arr[4], amount;
    arr[0] = material[0] / 2;
    arr[1] = material[1];
    arr[2] = 100;
    arr[3] = material[3] / 2;
    amount = min(arr);
    material[0] -= 2 * amount;
    material[1] -= amount;
    material[3] -= 2 * amount;
    printf("%d\n", amount);
}

void P2(){
    int arr[4], amount;
    arr[0] = material[0];
    arr[1] = material[1];
    arr[2] = material[2];
    arr[3] = material[3];
    amount = min(arr);
    material[0] -= amount;
    material[1] -= amount;
    material[3] -= amount;
    printf("%d\n", amount);
}

void P3(){
    int arr[4], amount;
    arr[0] = 100;
    arr[1] = 100;
    arr[2] = material[2] / 2;
    arr[3] = material[3];
    amount = min(arr);
    material[2] -= 2 * amount;
    material[3] -= amount;
    printf("%d\n", amount);
}

void P4(){
    int arr[4], amount;
    arr[0] = 100;
    arr[1] = material[1] / 3;
    arr[2] = 100;
    arr[3] = 100;
    amount = min(arr);
    material[1] -= 3 * amount;
    printf("%d\n", amount);
}

void P5(){
    int arr[4], amount;
    arr[0] = material[0];
    arr[1] = 100;
    arr[2] = 100;
    arr[3] = material[3];
    amount = min(arr);
    material[0] -= amount;
    material[3] -= amount;
    printf("%d\n", amount);
}

int main(){
    scanf("%d %d %d %d", &material[0], &material[1], &material[2], &material[3]);
    P1();
    P2();
    P3();
    P4();
    P5();
    return 0;
}