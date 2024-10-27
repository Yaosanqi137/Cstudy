#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define G 6.674e-6 // 加大引力常数

int time = 0; // 这个宇宙的最重要的单位
int xLimit = 60;
int yLimit = 40;

typedef struct {
    double mass;
    double position[2];
    double velocity[2];
    double force[2];
} Physics;

double distance(double pos1[2], double pos2[2]);
double sinDirect(double pos1[2], double pos2[2]);
double cosDirect(double pos1[2], double pos2[2]);
void gravity(Physics *particle1, Physics *particle2);
void crash(Physics *particle1, Physics *particle2);
void moveHandler(Physics *particle);
void simulation(Physics particles[], int number, int total);

double distance(double pos1[2], double pos2[2]){
    return sqrt(pow((pos1[0] - pos2[0]), 2) + pow((pos1[1] - pos2[1]), 2));
}

void crash(Physics *particle1, Physics *particle2){
    double dist = distance(particle1->position, particle2->position);
    if(dist <= sqrt(2)){
        particle1->velocity[0] = ((particle1->mass - particle2->mass) + 2 * particle2->mass * particle2->velocity[0]) / (particle2->mass + particle1->mass);
        particle1->velocity[1] = ((particle1->mass - particle2->mass) + 2 * particle2->mass * particle2->velocity[1]) / (particle2->mass + particle1->mass);
    }
}

double sinDirect(double pos1[2], double pos2[2]){
    return (pos2[1] - pos1[1]) / distance(pos1, pos2);
}

double cosDirect(double pos1[2], double pos2[2]){
    return (pos2[0] - pos1[0]) / distance(pos1, pos2);
}

void gravity(Physics *particle1, Physics *particle2){
    double dist = distance(particle1->position, particle2->position);
    if(dist == 0){
        return;
    }
    double gravityForce = G * particle1->mass * particle2->mass / (dist * dist);
    particle1->force[0] += gravityForce * cosDirect(particle1->position, particle2->position);
    particle1->force[1] += gravityForce * sinDirect(particle1->position, particle2->position);
}

double centripetalForce(){

}

void moveHandler(Physics *particle){
    double aX = particle->force[0] / particle->mass;
    double aY = particle->force[1] / particle->mass;
    printf("\nforce: %lf N, %lf N", particle->force[0], particle->force[1]);
    printf("\nacceleration: %lf m/s^2, %lf m/s^2", aX, aY);
    // 加速度处理
    particle->velocity[0] += aX;
    particle->velocity[1] += aY;
    printf("\nvelocity: %lf m/s, %lf m/s", particle->velocity[0], particle->velocity[1]);
    // 速度处理
    particle->position[0] += particle->velocity[0];
    particle->position[1] += particle->velocity[1];
    if(particle->position[1] >= yLimit){
        particle->position[1] = yLimit - 1;
        particle->velocity[1] = -particle->velocity[1];
    }else if(particle->position[0] >= xLimit){
        particle->position[0] = xLimit - 1;
        particle->velocity[0] = -particle->velocity[0];
    }else if(particle->position[1] < 0){
        particle->position[1] = 0;
        particle->velocity[1] = -particle->velocity[1];
    }else if(particle->position[0] < 0){
        particle->position[0] = 0;
        particle->velocity[0] = -particle->velocity[0];
    }
    printf("\nx, y: %lfm, %lf m", particle->position[0], particle->position[1]);
    // 位移处理
}

void simulation(Physics particles[], int number, int total){
    printf("\npoint%d:", number + 1);
    printf("\nmass: %lf kg", particles[number].mass);
    particles[number].force[0] = 0, particles[number].force[1] = 0; // 先将之前的力清空
    for(int n = 0;n < total;n++){
        if(n == number)
            continue;
        gravity(&particles[number], &particles[n]);
        crash(&particles[number], &particles[n]);
    }
    // 先计算力的向量
    moveHandler(&particles[number]);
    // 计算运动位移
}

int main(){
    int amount, limitTime, check;
    printf("请输入你想要引入几个质点:");
    scanf("%d", &amount);
    Physics *particles = (Physics *)malloc(amount * sizeof(Physics));
    for(int n = 1;n <= amount;n++){
        printf("请输入第%d个质点的质量(kg):", n);
        scanf("%lf", &particles[n - 1].mass);
        printf("请输入第%d个质点的坐标(x,y)(m):", n);
        scanf("%lf,%lf", &particles[n - 1].position[0], &particles[n - 1].position[1]);
        printf("请输入第%d个质点的初速度以及方向(x,y)(m/s):", n);
        scanf("%lf,%lf", &particles[n - 1].velocity[0], &particles[n - 1].velocity[1]);
    }
    printf("请问你想要模拟多少步:");
    scanf("%d", &limitTime);
    // 录入数据模块
    for(;time <= limitTime;time++){
        for(int i = 0;i < amount;i++){
            simulation(particles, i, amount);
        }
        // 计算模块
        printf("\n");
        check = 0;
        for(int y = 0;y <= yLimit;y++){
            for(int x = 0;x <= xLimit;x++){
                if(y == yLimit){
                    printf("**");
                    continue;
                }
                for(int point = 0;point < amount;point++){
                    if(x == (int)particles[point].position[0] && y == (int)particles[point].position[1]){
                        printf("%d ", point + 1);
                        check += 1;
                    }
                }
                if(check != 0){
                    check--;
                    continue;
                }
                if(x == xLimit)
                    printf("**");
                else
                    printf("  ");
            }
            printf("\n");
        }
        printf("step:%d/%d", time, limitTime);
        // 显示模块
        Sleep(700);
        system("cls");
    }

    putchar('\n');
    free(particles);
    system("pause");
    return 0;
}
