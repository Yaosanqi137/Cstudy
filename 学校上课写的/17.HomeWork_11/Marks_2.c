// 8.15
#include <stdio.h>
#define STU 7
#define SUB 5

float ave(float (*p)[SUB]){
    float sum = 0;
    for(int i = 0; i < STU; i++, p++){
        sum += (*p)[0];
    }
    return sum / STU;
}

float *fail(float (*p)[SUB]){
    int count = 0;
    for(int j = 0; j < SUB; j++)
        if((*p)[j] <= 60)
            count++;
    if(count >= 2)
        return *p;
    else
        return NULL;
}

float *good(float (*p)[SUB]){
    int count = 0;
    float sum = 0;
    for(int j = 0; j < SUB; j++){
        if((*p)[j] >= 85)
            count++;
        sum += (*p)[j];
    }
    if(count == 5 || (sum / SUB) >= 90)
        return *p;
    else
        return NULL;
}

int main(){
    float mark[STU][SUB] = {
            {84, 91, 93, 92, 87.5}, // {84, 91, 93, 92, 87.5}
            {63, 65, 87, 72, 92},   // {63, 65, 87, 72, 92}
            {51, 78, 77, 65, 47},   // {51, 78, 77, 65, 47}
            {85, 86, 87, 90, 84},   // {85, 86, 87, 90, 84}
            {87, 85, 91, 85, 89},   // {87, 85, 91, 85, 89}
            {73, 56, 47, 52, 81},   // {73, 56, 47, 52, 81}
            {99, 98, 97, 58, 98}    // {99, 98, 97, 58, 98}
            }, *p, sum;                                     // 原始数据
    int check = 1;
    for(int i = 0; i < STU; i++){
        printf("(%d)", i + 1);
        for(int j = 0; j < SUB; j++)
            printf("%.1f ", mark[i][j]);
        putchar('\n');
    }
    putchar('\n');
    printf("第1门课程的平均分为 %.2f\n\n", ave(mark));
    printf("两门以上成绩不及格的学生为:\n");
    for(int j = 0; j < STU; j++){
        p = fail(&mark[j]);
        if(p){
            printf("(%d) ", j + 1);
            sum = 0;
            for(int k = 0; k < SUB; k++, p++){
                printf("%.1f ", *p);
                sum += *p;
            }
            printf("  %.2f\n", sum / SUB);
        }
    }
    putchar('\n');
    printf("平均成绩在90分以上或全部成绩在85分以上的学生的信息为:\n");
    for(int j = 0; j < STU; j++){
        p = good(&mark[j]);
        if(p){
            check  = 0;
            printf("(%d) ", j + 1);
            sum = 0;
            for(int k = 0; k < SUB; k++, p++){
                printf("%.1f ", *p);
                sum += *p;
            }
            printf("  %.2f\n", sum / SUB);
        }
    }
    if(check)
        putchar('\n');
    return 0;
}