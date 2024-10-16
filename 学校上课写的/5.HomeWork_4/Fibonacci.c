#include <stdio.h>

int main(){
    int n, i = 0, count = 0;
    double a = 1, b = 0, c, sum = 0;
    printf("?????? n ?:");
    scanf("%d", &n);
    while(1){
        c = b;
        b = a;
        a += c;
        count++;
        if(count % 2 == 1){
            sum += b / a;
            i++;
            if(sum > n){
                sum -= b / a;
                i--;
                break;
            }
        }
    }
    printf("????? %d ??,????:%lf\n", i, sum);
    return 0;
}