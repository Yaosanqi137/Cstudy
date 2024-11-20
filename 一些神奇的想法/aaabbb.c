#include <stdio.h>

int main(){
    char str[64];
    int checkA = 0, checkB = 0, lock = 1;
    scanf("%s", str);
    for(int i = 0; str[i]; i++){
        if(str[i] == 'b' && lock){
            checkB = i + 1;
            lock = 0;
        }
        if(str[i] == 'a')
            checkA = i + 1;
    }
    if(checkA <= checkB || !checkB)
        printf("True");
    else
        printf("False");
    return 0;
}