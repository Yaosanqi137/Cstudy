#include <stdio.h>

int main(){
    int array[64] = {0}, max;
    for(int i = 0; getchar() != '\n'; i++){
        scanf("%d", &array[i]);
        if(!i)
            max = array[i];
        else if(max < array[i])
            max = array[i];
    }
    printf("%d\n", max);
    return 0;
}