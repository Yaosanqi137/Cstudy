// 也就是实现了一个中位数获取器
#include <stdio.h>

struct node{
    float num;
    struct node *next;
};

void print(struct node *p){
    while(p != NULL){
        printf("%.1f\n", p->num);
        p = p->next;
    }
    putchar('\n');
}

float median(struct node *head){
    struct node *p0, *p1, *p2;
    p1 = p2 = head;
    while(p2 != NULL){
        p2 = p2->next;
        if(p2 != NULL){
            p2 = p2->next; // p2每次都跳两位
            p0 = p1;       // p0保证每次都在p1前一位
            p1 = p1->next; // p1在最后都在中间
        }else
            return p1->num; // 如果链表长度是奇数，p2进入循环后还不是NULL,再跳一位就是NULL了，此时就会直接返回p1的值
    }
    return (p0->num + p1->num) / 2; // 否则p2在进入循环之前就NULL了，就会返回p1和p0的平均值
}

int main(){
    struct node ca[7] = {{3, 0}, {4, 0}, {6, 0}, {9, 0}, {15, 0}, {20, 0}, {21, 0}};
//    struct node ca[6] = {{20, 0}, {15, 0}, {9, 0}, {6, 0}, {4, 0}, {3, 0}};
//    struct node ca[6] = {{3, 0}, {4, 0}, {6, 0}, {9, 0}, {15, 0}, {20, 0}};
//    struct node ca[5] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};
//    struct node ca[4] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
//    struct node ca[3] = {{1, 0}, {2, 0}, {3, 0}};
//    struct node ca[2] = {{1, 0}, {2, 0}};
//    struct node ca[1] = {{1, 0}};
//    struct node ca[5] = {{3.6, 0}, {4.1, 0}, {5.7, 0}, {9.8, 0}, {15.2, 0}};
    struct node *head = ca;
    int i;
    for(i = 0; i < 7 - 1; i++)
        ca[i].next = &ca[i + 1];
    ca[i].next = NULL;
    print(head);
    if(head)
        printf("value=%.1f\n", median(head));
    else
        printf("The chain is empty!\n");
    return 0;
}
