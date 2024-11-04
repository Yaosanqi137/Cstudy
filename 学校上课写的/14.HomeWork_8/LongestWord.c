// 7.10
#include <stdio.h>
#include <string.h>

int main(){
    char str[64], longest[64] = "";
    int strlen, len = 0;
    printf("请输入字符序列:");
    do{
        scanf("%s%n", str, &strlen);
        if(strlen > len){
            strcpy(longest, str);
            len = strlen;
        }
    }while(getchar() != '\n');
    printf("最长单词为:%s", longest);
    return 0;
}
