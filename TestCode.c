// TestCode.c
#include <stdio.h>
#define MAX_LEN 500

int checkDNA(char str[2][MAX_LEN], int len){
    int count = 0;
    for(int i = 0; i < len; i++)
        if(str[0][i] == str[1][i])
            count++;
    return count;
}
