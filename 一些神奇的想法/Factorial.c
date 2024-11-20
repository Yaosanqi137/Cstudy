#include <stdio.h>

int factorial(int m){
    int result = 1;
    if(!m)
        return 1;
    else if(m > 0)
        for(int i = 2; i <= m; i++)
            result *= i;
    else
        return -1;
    return result;
}

int main(){
    int m;
    scanf("%d", &m);
    printf("%d", factorial(m));
}
