#include <stdio.h>
#define MAX_LEN 500

int checkDNA(char str[2][MAX_LEN], int len){
    int count = 0;
    for(int i = 0; i < len; i++)
        if(str[0][i] == str[1][i])
            count++;
    return count;
}

int main(){
    double threshold;
    char str[2][MAX_LEN];
    int len;
    scanf("%lf", &threshold);
    scanf("%s", str[0]);
    scanf("%s%n", str[1], &len);
    if((checkDNA(str, len) / (double)len) < threshold)
        printf("no");
    else
        printf("yes");
    return 0;
}