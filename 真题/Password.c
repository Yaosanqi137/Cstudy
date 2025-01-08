#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 100
#define MAX_LEN 80

char passwd[MAX_N][MAX_LEN];

int isLegal(char str[MAX_LEN]){
    int hasNum = 0, hasAlp = 0;
    if(strlen(str) < 6)
        return 1;
    for(int i = 0; str[i]; i++)
        if(isdigit(str[i]))
            hasNum = 1;
        else if(isalpha(str[i]))
            hasAlp = 1;
        else if(str[i] != '.')
            return 2;
    if(!hasNum)
        return 3;
    else if(!hasAlp)
        return 4;
    return 0;
}

int main(){
    int n, code;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", passwd[i]);
    for(int i = 0; i < n; i++){
        code = isLegal(passwd[i]);
        switch(code){
            case 0:
                printf("Your password is wan mei.\n");
                break;
            case 1:
                printf("Your password is tai duan le.\n");
                break;
            case 2:
                printf("Your password is tai luan le.\n");
                break;
            case 3:
                printf("Your password needs shu zi.\n");
                break;
            case 4:
                printf("Your password needs zi mu.\n");
        }
    }
    return 0;
}