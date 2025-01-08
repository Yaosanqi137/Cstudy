// 2021 A
#include <stdio.h>
#include <string.h>
#define MAX 100 // 一天最多走128步
#define MAX_LEN 24
#define MAX_DAY 100

int pos[MAX_DAY]; // 初始坐标
int totalDay;
int totalFoot;
int footPoint[MAX];
char foot[MAX_LEN];
int day, p;

int main(){
    while(scanf("%d", &totalFoot) > 0){
        getchar();
        for(int i = 0; i < totalFoot; i++){
            fgets(foot, MAX_LEN, stdin);
            foot[strlen(foot) - 1] = '\0';
            if(foot[0] == 'L')
                pos[day]--;
            else if(foot[0] == 'R')
                pos[day]++, footPoint[i] = 1;
            else{
                sscanf(foot, "SAME AS %d", &p);
                if(!footPoint[p - 1])
                    pos[day]--;
                else
                    pos[day]++, footPoint[i] = 1;
            }
        }
        day++;
    }

    for(int i = 0; i < day; i++)
        printf("%d\n", pos[i]);
    return 0;
}