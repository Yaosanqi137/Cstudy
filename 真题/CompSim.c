#include <stdio.h>

int M1, M2, R1 = 0, R2 = 0, R3 = 0;

int main(){
    char COMMAND;
    scanf("%d %d", &M1, &M2);
    while(scanf("%c", &COMMAND) != EOF){
        switch(COMMAND){
        case 'A':
            R1 = M1;
            break;
        case 'B':
            R2 = M2;
            break;
        case 'C':
            M1 = R3;
            break;
        case 'D':
            M2 = R3;
            break;
        case 'E':
            R3 = R1 + R2;
            break;
        case 'F':
            R3 = R1 - R2;
            break;
        }
    }
    printf("%d,%d", M1, M2);
    return 0;
}