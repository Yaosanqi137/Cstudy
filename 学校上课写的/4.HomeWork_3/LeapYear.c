// 在指定的范围内检测是否为闰年
#include <stdio.h>

int main(){
    int start, end, count = 0;
    printf("请输入起止年份:");
    scanf("%d,%d", &start, &end);
    printf("%d - %d 年之间的闰年有:\n", start, end);
    for(int year = start;year <= end;year++){
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
            printf("%d  ", year);
            count++;
            if (count % 10 == 0) // 每输出10个闰年就换行
                printf("\n");
        }
    }
    printf("\n");
    return 0;
}