// 8.5
#include <stdio.h>
#define N 100

struct List{
    int value;
    struct List *left;
    struct List *right;
};

void Joseph(struct List ring[], int people, int num){
    int out = 0, sign = 0, count = 0;
    while (out < people) {
        count++;
        if(count == num){
            ring[ring[sign].left->value].right = ring[sign].right;
            ring[ring[sign].right->value].left = ring[sign].left;
            printf("%4d", sign + 1);
            count = 0;
            if(!(++out % 10))
                putchar('\n');
        }
        sign = ring[sign].right->value;
    }
    if(out % 10)
        putchar('\n');
}

int main(){
    struct List list[N];
    int people, num;
    printf("请输入人数(1-100):");
    scanf("%d", &people);
    printf("请输入报数(1-10):");
    scanf("%d", &num);
    printf("离开的顺序为:\n");
    for(int i = 0; i < people; i++){
        list[i].value = i;
        list[i].left = &list[(i + people - 1) % people];
        list[i].right = &list[(i + 1) % people];
    }
    Joseph(list, people, num);
    return 0;
}