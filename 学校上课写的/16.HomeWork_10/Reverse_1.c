// 8.4
#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6,7};

void reverse(int len, int time){
    int *p, t;
    time %= len;
    for(int i = 0; i < time; i++){
        p = arr + len - 1;
        t = *p;
        while(p != arr){
            *p = *(p - 1);
            p--;
        }
        *p = t;
    }
}

int main(){
    int time, length = 0;
    for(int i = 0; arr[i]; i++){
        printf("%d ", arr[i]);
        length++;
    }
    putchar('\n');
    printf("请输入位移位数:");
    scanf("%d", &time);
    printf("结果为");
    reverse(length, time);
    for(int i = 0; arr[i]; i++)
        printf("%d ", arr[i]);
    putchar('\n');
    return 0;
}
