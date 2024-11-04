#include <stdio.h>
#include <string.h>

void showStr(char ch[], int left, int right){
    for(int j = 0; j < left; j++)
        printf("*");
    for(int i = left; i <= right; i++)
        if(ch[i] != '*')
            printf("%c", ch[i]);
    for(int k = right + 1; k < strlen(ch); k++)
        printf("*");
}

int main(){
    char ch[256];
    scanf("%s", &ch);
    int check1 = 0, check2 = -1, left = 0, right = strlen(ch) - 1;
    while(1){
        if(ch[left] == '*')
            left++;
        else{
            check1 = 1;
        }
        if(ch[right] == '*')
            right--;
        else{
            check2 = 1;
        }
        if(check1 == check2)
            break;
    }
    showStr(ch, left, right);
    return 0;
}