// 8.5
#include <stdio.h>
#define N 100

void josephRing(int arr[], int people, int num){
    int pre = people - 1, out = 0, count = 0, now = 0;
    while(out < people){
        count++;
        if(count == num){
            printf("%4d", now + 1);
            if(!(out++ % 10))
                putchar('\n');
            arr[pre] = arr[now];
            count = 0;
        }else
            pre = now;
        now = arr[now];
    }
    if(out % 10)
        putchar('\n');
}

int main(){
    int ring[N];
    int people, num;
    printf("请输入人数(1-100):");
    scanf("%d", &people);
    printf("请输入报数(1-10):");
    scanf("%d", &num);
    printf("离开的顺序为:\n");
    for(int i = 0; i < people; i++)
        ring[i] = (i + 1) % people;
    josephRing(ring, people, num);
    return 0;
}
