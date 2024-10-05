#include <stdio.h>

void isPrime(int IN){
    for(int checkNumber = 2;checkNumber < IN;checkNumber++){
        if(IN %  checkNumber == 0){
            return;
        }
    }
    printf("%d 是素数\n", IN);
}

int main(){
    printf("你想检查到素数的范围: ");
    int numRange;
    scanf("%d", &numRange);

    for(int check = 2;check <= numRange;check++){ // 逐一检查是否为素数
        isPrime(check);
    }
    getchar();
}
