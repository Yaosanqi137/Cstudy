#include <stdio.h>

int isInt(float num){
    if(num - (int)num)
        return 0;
    return 1;
}

int main(){
    int head, feet;
    float cock, rabbit;
    scanf("%d %d", &head, &feet);
    rabbit = (feet - 2 * head) / 2.0;
    if(rabbit < 0 || !isInt(rabbit)){
        printf("题目无解");
        return 0;
    }
    cock = head - rabbit;
    if(rabbit >= 0 && cock >= 0)
        printf("共有%d只鸡\n共有%d只兔", (int)cock, (int)rabbit);
    else
        printf("题目无解");
    return 0;
}