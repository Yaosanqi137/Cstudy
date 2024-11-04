// 7.14
#include <stdio.h>
#define S 3 // 学生数
#define C 5 // 课程数

double sum(int len, double arr[len]){
    double sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

double powSum(int len, double arr[len]){
    double sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i] * arr[i];
    return sum;
}

double classAve(int students, int subjects, int subject, double arr[students][subjects]){
    double sum = 0;
    for(int i = 0; i < students; i++)
        sum += arr[i][subject];
    return sum / students;
}

double scoreAve(int subjects, double arr[subjects]){
    double sum = 0;
    for(int i = 0; i < subjects; i++)
        sum += arr[i];
    return sum / subjects;
}

int main(){
    double marks[S][C], subjAve[C], stuAve[S], highest = 0, var, sums, powSums;
    int stu, subj;
    for(int i = 0; i < S; i++)
        for(int j = 0; j < C; j++)
            scanf("%lf", &marks[i][j]);
    // 输入数据
    for(int n = 0; n < S; n++){
        stuAve[n] = scoreAve(C, marks[n]);
        printf("第%d个同学的平均分为%.2lf\n", n + 1, stuAve[n]);
    }
    // 每位学生的平均分
    for(int n = 0; n < C; n++){
        subjAve[n] = classAve(S, C, n, marks);
        printf("第%d门课程的平均分为%.2lf\n", n + 1, subjAve[n]);
    }
    // 全局最高分
    for(int i = 0; i < S; i++){
        for(int j = 0; j < C; j++){
            if(marks[i][j] > highest){
                highest = marks[i][j];
                stu = i;
                subj = j;
            }
        }
    }
    printf("最高分为%.1lf,是第%d个学生的第%d门课程\n", highest, stu + 1, subj + 1);
    // 最高分和对应的学生、科目
    sums = sum(S, stuAve);
    powSums = powSum(S, stuAve);
    var = powSums / S - (sums / S) * (sums / S);
    printf("学生均分的方差为%.3lf\n", var);
    // 计算方差
    return 0;
}
