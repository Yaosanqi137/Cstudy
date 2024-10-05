#include <stdio.h>

int main(){
    int m,n,x,y;
    for(m = 0; m <= 64; m++){
        for(n = 0; n <= 64; n++){
            x = (n + m)*(n - m);
            if(x == 168){
                y = m*m - 100;
                printf("\n%d + 100 = %d^2", y, m);
                printf("\n%d + 100 + 168 = %d^2", y, n);
            }
        }
    }
}