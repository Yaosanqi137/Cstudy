#include <stdio.h>
#define N 64
// 链表结构示例
struct List{
    int value;
    struct List *left;
    struct List *right;
};

int main(){
    struct List list[N];
    for(int i = 0; i < 16; i++){
        list[i].value = i + 1;
        list[i].left = &list[(i + N - 1) % N];
        list[i].right = &list[(i + 1) % N];
    }
}