#include <stdio.h>

int main(){
    int map[1000000] = {0};
    int n, index, max = 0, min = 1000, count, num1 = 0, num2 = 0, cost = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &index);
        if(index > max)
            max = index;
        if(index < min)
            min = index;
        map[index]++;
    }
    while(n > 1){
        count = 0;
        for(int j = min; j <= max; j++){
            switch(map[j]){
                case 1:
                    map[j]--;
                    if(!num1) num1 = j;
                    else num2 = j;
                    count++;
                    break;
                case 0:
                    break;
                default:
                    if(!num1){
                        map[j] -= 2;
                        num1 = num2 = j;
                    }else{
                        map[j]--;
                        num2 = j;
                    }
                    count = 2;
            }
            if(count == 2){
                n--;
                map[num1 + num2]++;
                min = num2;
                if(num1 + num2 > max)
                    max = num1 + num2;
                cost += num1 + num2;
                num1 = num2 = 0;
                break;
            }
        }
    }
    printf("%d", cost);
    return 0;
}