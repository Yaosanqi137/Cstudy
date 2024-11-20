#include <stdio.h>

int sum(int num){
    int sum = 0;
    if(num < 37)
        return 0;
    else
        for(int i = 37; i < num; i += 37)
            sum += i;
    return sum;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", sum(num));
}