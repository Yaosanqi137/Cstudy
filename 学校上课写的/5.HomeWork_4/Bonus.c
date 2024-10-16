#include <stdio.h>

int main(){
    double I = 0, bonus;
    printf("ÀûÈó(Ôª):");
    scanf("%lf", &bonus);
    
    while(bonus != 0){
        if(bonus <= 1e5){
            I += bonus * 0.1;
            bonus = 0;
        }else if(bonus <= 2e5){
            bonus -= 1e5;
            I += bonus * 0.075;
            bonus = 1e5;
        }else if(bonus <= 4e5){
            bonus -= 2e5;
            I += bonus * 0.05;
            bonus = 2e5;
        }else if(bonus <= 6e5){
            bonus -= 4e5;
            I += bonus * 0.03;
            bonus = 4e5;
        }else if(bonus <= 1e6){
            bonus -= 6e5;
            I += bonus * 0.015;
            bonus = 6e5;
        }else if(bonus > 1e6){
            bonus -= 1e6;
            I += bonus * 0.01;
            bonus = 1e6;
        }
    }

    printf("½±½ð:%.2lf\n", I);
    return 0;
}