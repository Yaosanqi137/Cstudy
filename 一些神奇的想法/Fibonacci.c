#include <stdio.h>

int fibo(int m){
    int f0 = 0, f1 = 1, sum = 0;
    if(!m)
        return f0;
    else if(m == 1)
        return f1;
    else
        for(int i = 1; i < m; i++) {
            sum = f1 + f0;
            f0 = f1;
            f1 = sum;
        }
    return sum;
}

int main(){
    int m;
    scanf("%d", &m);
    printf("%d", fibo(m));
    return 0;
}