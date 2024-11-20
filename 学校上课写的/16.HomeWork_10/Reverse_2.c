// 8.4
#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6,7};

void reverse(int start, int end){
    int *p = arr + start;
    int *q = arr + end;
    int t;
    while(p <= q){
        t = *p;
        *p = *q;
        *q = t;
        p++, q--;
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
    printf("结果为:");
    time %= length;
    reverse(0, length - time - 1);
    reverse(length - time, length - 1);
    reverse(0, length - 1);
    for(int i = 0; arr[i]; i++)
        printf("%d ", arr[i]);
    putchar('\n');
    return 0;
}
