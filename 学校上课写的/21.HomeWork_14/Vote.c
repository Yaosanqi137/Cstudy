// 10.13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 1000

const char *DATAFILE = "vote.dat";

struct vote {
    char voterName[20];
    int goodsID;
    float point;
};

struct vote voter[M];
struct vote buffer;

struct count {
    float sum;
    int n;
} goods[N];

void dataIn(){
    int id, count = 0;
    char name[20];
    while(1){
        printf("投票人姓名:");
        scanf("%s", name);
        if(!strcmp(name, "exit")){
            break;
        }
        while(1){
            printf("\n商品编号:");
            scanf("%d", &id);
            if(!id)
                break;
            else if(id > N || id < 0){
                printf("输入有误!请重新输入!\n");
                continue;
            }
            strcpy(voter[count].voterName, name);
            voter[count].goodsID = id;
            while(1){
                printf("评分:");
                scanf("%f", &voter[count].point);
                if(voter[count].point >= 0 && voter[count].point <= 10)
                    break;
                else
                    printf("输入有误!请程序输入(0 ~ 10)\n");
            }
            count++;
        }
    }
    putchar('\n');
    // 数据输入

    FILE *fp = fopen(DATAFILE, "a+b");
    if(fp == NULL){
        perror("无法打开数据文件!");
        exit(EXIT_FAILURE);
    }
    fwrite(voter, sizeof(struct vote), count, fp);
    fclose(fp);
    // 数据录入
}

void dataOut(){
    FILE *fp = fopen(DATAFILE, "r+b");
    if(fp == NULL){
        perror("无法打开数据文件!");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while(fread(&buffer, sizeof(struct vote), 1, fp))
        voter[count++] = buffer;
    for(int i = 0; i < count; i++)
        printf("%-12s %-6d    %-6.1f\n", voter[i].voterName, voter[i].goodsID, voter[i].point);
    for(int i = 0; i < count; i++){
        goods[voter[i].goodsID - 1].n++;
        goods[voter[i].goodsID - 1].sum += voter[i].point;
    }
    putchar('\n');
}

void printAll(){
    printf("****商品评分信息一览表****\n");
    for(int i = 0; i < N; i++)
        if(goods[i].n)
            printf("%2d.       %-4d    %.2f\n", i + 1, goods[i].n, goods[i].sum / goods[i].n);
    putchar('\n');
}

void process(){
    float max = -1, ave;
    int id;
    for(int i = 0; i < N; i++)
        if(goods[i].n >= 2 && (ave = goods[i].sum / goods[i].n) > max)
            max = ave, id = i;
    printf("最受欢迎的商品信息(评分人数不少于2人):\n%2d       %-4d    %.2f\n", id + 1, goods[id].n, max);
}

int main(){
    dataIn();
    dataOut();
    printAll();
    process();
    return 0;
}