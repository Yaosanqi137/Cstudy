// 分析输出
#include <stdio.h>

int main(){
    for(int i = 'Y';i <= 'Z';i++){ // 这里原来有个 if(i = 'X') continue;的，我优化掉了
        for(int j = 'X';j <= 'Z';j++){
            if(i == j)
                continue;
            for(int k = 'X';k <= 'Z';k++){
                if(k == i || k == j || k == 'X' || k =='Z')
                    continue;
                printf("The match is: A--%c, B--%c, C--%c", i, j, k); //输出 The match is: A--Z, B--X, C--Y
            }
        }
    }
}
