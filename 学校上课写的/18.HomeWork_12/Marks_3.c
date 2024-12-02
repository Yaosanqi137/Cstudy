// 9.5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define STU 3
#define SUB 4

struct birthday {
    int yyyy, mm, dd;
};

struct student {
    long long id;
    char name[16];
    char sex;
    struct birthday birth;
    float score[SUB];
};

void output(struct student stu[], int i, float ave[]){
    printf("%-5d ", i + 1);
    printf("%-11lld ", stu[i].id);
    printf("%-9s ", stu[i].name);
    printf((stu[i].sex) == 'M' ? "男  " : "女  ");
    printf("%d-%02d-%02d  ", stu[i].birth.yyyy, stu[i].birth.mm, stu[i].birth.dd);
    for(int j = 0; j < SUB; j++)
        printf("%-8.1f", stu[i].score[j]);
    printf("%.2f", ave[i]);
    putchar('\n');
}

int sort(float arr[], int n){
    float max = arr[0];
    int term = 0;
    for(int i = 1; i < n; i++)
        if(max < arr[i])
            term = i;
    return term;
}

float sum(float arr[], int len){
    float sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    return sum / len;
}

int main(){
    srand(time(NULL));
    struct student stu[STU];
    float ave[STU];
    for(int i = 0; i < STU; i++){
        printf("请输入第%d个学生的信息\n", i + 1);
        printf("学号:"); scanf("%lld", &stu[i].id);
        printf("姓名:"); scanf("%s", stu[i].name);
        printf("性别(M/F):"); getchar(); stu[i].sex = getchar();
        printf("生日:"); scanf("%d-%d-%d", &stu[i].birth.yyyy, &stu[i].birth.mm, &stu[i].birth.dd);
        putchar('\n');
    }
    for(int i = 0; i < STU; i++){
        for(int j = 0; j < SUB; j++)
            stu[i].score[j] = (120 + rand() % 80) / 2;
        ave[i] = sum(stu[i].score, SUB);
    }
    printf("序号    学号        姓名     性别    生日     第一门   第二门   第三门    第四门    平均\n");
    for(int i = 0; i < STU; i++){
        output(stu, i, ave);
    }
    putchar('\n');
    printf("平均成绩最高的学生信息为\n");
    output(stu, sort(ave, STU), ave);
    return 0;
}