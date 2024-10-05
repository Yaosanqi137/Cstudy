#include "func_repo.h"

void isPrime(int IN){
    for(int checkNumber = 2;checkNumber < IN;checkNumber++){
        if(IN %  checkNumber == 0){
            return;
        }
    }
    printf("%d ÊÇËØÊý\n", IN);
}