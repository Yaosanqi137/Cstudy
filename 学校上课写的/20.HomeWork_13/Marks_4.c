// 9.15
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

int count;

struct student {
    long num;
    float score;
    struct student *next;
};

struct student *del(struct student *head, long target){
    struct student *temp, *p = head;
    if(head != NULL){
        while(target > p->num && p->next != NULL){
            temp = p;
            p = p->next;
        }
        if(target == p->num){
            if(head == p)
                head = p->next;
            else
                temp->next = p->next;
            printf("Deleted, %ld\n", target);
            count--;
            free(temp);
        }else{
            printf("%ld not been find!", target);
        }
    }else
        printf("List is null!\n");
    return head;
}

struct student *insert(struct student *head, struct student *p){
    struct student *p0 = head, *p1 = p, *temp;
    if(head == NULL){
        head = p1;
        p1->next = NULL;
    }else{
        while(p1->num > p0->num && p0->next){
            temp = p0;
            p0 = p0->next;
        }
        if(p0->num >= p1->num){
            if(head == p0)
                head = p1;
            else
                temp->next = p1;
            p1->next = p0;
        }else{
            p0->next = p1;
            p1->next = NULL;
        }
    }
    count++;
    return head;
}

struct student *create(){
    struct student *head, *p;
    p = (struct student *)malloc(LEN);
    scanf("%ld,%f", &p->num, &p->score);
    head = NULL;
    while(p->num || p->score){
        head = insert(head, p);
        p = (struct student *)malloc(LEN);
        scanf("%ld,%f", &p->num, &p->score);
    }
    free(p);
    return head;
}

void print(struct student *head){
    struct student *p = head;
    if(count){
        printf("\nNow, These %d records are:\n", count);
        do{
            printf("%ld %5.1f\n", p->num, p->score);
            p = p->next;
        }while(p);
    }else{
        printf("\nSorry! No records now!\n");
    }
}

int main(){
    struct student *head, *p;
    int choice = -1;
    long target;
    printf("*****Create list!*****\n");
    printf("Please input records: (0,0 for exit):\n");
    head = create();
    print(head);
    putchar('\n');
    while(choice){
        printf("1. INSERT       2. DELETE       0. EXIT\n");
        printf("Please Choose:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Please input num and score:");
                p = (struct student *)malloc(LEN);
                scanf("%ld,%f", &p->num, &p->score);
                head = insert(head, p);
                printf("Inserted, %ld\n", p->num);
                print(head);
                putchar('\n');
                break;
            case 2:
                printf("Please input num:");
                scanf("%ld", &target);
                head = del(head, target);
                print(head);
                putchar('\n');
                break;
            case 0:
                break;
            default:
                printf("Error! Input again!\n\n");
                while(getchar() != '\n');
        }
    }
    free(p);
    return 0;
}