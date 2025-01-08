#include <stdio.h>
#include <string.h>
#define LEN 100

int ele[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

struct time {
    int score;
    int hh;
    int mm;
    int ss;
};

int timeCal(struct time n1, struct time n2){
    int s1 = n1.hh * 3600 + n1.mm * 60 + n1.ss;
    int s2 = n2.hh * 3600 + n2.mm * 60 + n2.ss;
    return s2 - s1;
}

int scoreCal(int m){
    char num[10];
    sprintf(num, "%d", m);
    int i = 0, total = 0;
    while(num[i])
        total += ele[num[i++] - 48];
    return total;
}

int main(){
    int i = 0, j, k = 0, total[10] = {0}, score;
    int m1[10] = {0}, m2[10] = {0};
    char str[LEN][LEN], *p;
    struct time start[10], end[10], score1[10][10], score2[10][10];
    while(fgets(str[i], LEN, stdin)) i++;
    for(j = 0; j <= i; j++)
        if(strstr(str[j], "START") != NULL)
            sscanf(str[j], "START %d:%d:%d\n", &start[k].hh, &start[k].mm, &start[k].ss);
        else if(strstr(str[j], "home") != NULL){
            sscanf(str[j], "SCORE %d:%d:%d home %d\n", &score1[k][m1[k]].hh, &score1[k][m1[k]].mm, &score1[k][m1[k]].ss, &score1[k][m1[k]].score);
            m1[k]++;
        }else if(strstr(str[j], "guest") != NULL) {
            sscanf(str[j], "SCORE %d:%d:%d guest %d\n", &score2[k][m2[k]].hh, &score2[k][m2[k]].mm, &score2[k][m2[k]].ss, &score2[k][m2[k]].score);
            m2[k]++;
        }else if(strstr(str[j], "END") != NULL){
            sscanf(str[j], "END %d:%d:%d\n", &end[k].hh, &end[k].mm, &end[k].ss);
            k++;
        }
    for(i = 0; i < k; i++){
        if(m1[i]){
            score = 0;
            total[i] += timeCal(start[i], score1[i][0]) * 6;
            for(j = 0; j < m1[i]; j++){
                score += score1[i][j].score;
                total[i] += timeCal(score1[i][j], score1[i][j + 1]) * scoreCal(score);
            }
            total[i] += timeCal(score1[i][j], end[i]) * scoreCal(score);
        }else
            total[i] += timeCal(start[i], end[i]) * 6;
        if(m2[i]){
            score = 0;
            total[i] += timeCal(start[i], score2[i][0]) * 6;
            for(j = 0; j < m2[i]; j++){
                score += score2[i][j].score;
                total[i] += timeCal(score2[i][j], score2[i][j + 1]) * scoreCal(score);
            }
            total[i] += timeCal(score2[i][j], end[i]) * scoreCal(score);
        }else
            total[i] += timeCal(start[i], end[i]) * 6;
    }
    for(i = 0; i < k; i++)
        printf("Case %d: %d\n", i + 1, total[i]);
    fflush(stdout);
    return 0;
}