#include <stdio.h>

int isLegal(int num, int pos){
    if(num >= 1 && num <= 17 && pos >= 'A' && pos <= 'F')
        return 0;
    return 1;
}

int main(){
    char pos;
    int num;
    scanf("%d%c", &num, &pos);
    if(isLegal(num, pos))
        printf("输入错误");
    else
        switch(pos){
        case 'A':
        case 'F':
            printf("窗口");
            break;
        case 'C':
        case 'D':
            printf("过道");
            break;
        case 'E':
            printf("中间");
        }
    return 0;
}