#include <stdio.h>

void encode(int input){
    if (65 <= input && input <= 90)
        input = (input - 61) % 26 + 65; // 这是比较完善的算法了，我可不想在这里写一大堆if-else来判断特殊情况
    else if (97 <= input && input <= 122)
        input = (input - 93) % 26 + 97;
    putchar(input);
}

int main(){
    int in, sleep;
    printf("请输入要加密的句子:");
    sleep = getchar();
    printf("加密文为:");
    encode(sleep);
    while((in = getchar()) != '\n')
        encode(in);
    printf("\n");
    return 0;
}