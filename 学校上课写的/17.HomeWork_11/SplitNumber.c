// 8.16
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 64
#define MAX_NUM 32
#define MAX_LEN 10

int isNum(char ch){
    if(ch >= 48 && ch <= 57)
        return 1;
    return 0;
}

void splitNum(char str[]){
    char nums[MAX_NUM][MAX_LEN] = {""};
    int count = 0, check = 0, k = 0;
    printf("%s\n", str);
    for(int i = 0; str[i]; i++){
        if(isNum(str[i])){
            if(!check)
                check = 1, count++;
            nums[count - 1][k++] = str[i];
        }else{
            check = 0, k = 0;
        }
    }
    printf("共有%d个整数,分别为:\n", count);
    for(int j = 0; j < count; j++)
        printf("%s ", nums[j]);
    if(count)
        putchar('\n');
}

int main(){
//    char str[64] = "A213x456 17960? 302tab5876";
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE - 1, stdin);
    str[strlen(str) - 2] = '\0';
    splitNum(str);
    return 0;
}