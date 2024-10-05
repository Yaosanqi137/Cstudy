// 老师没有布置要写解密程序的，我没事干顺便写的
#include <stdio.h>

void decode(int in){
    if(65 <= in && in < 90)
        in = (in - 4 < 65) ? (in - 4 + 26) : (in - 4); // 三元运算符，其实也就是个精简版if-else Usage:条件 ? 成立的话干什么 : 不成立干什么
    else if(97 <= in && in < 122)
        in = (in - 4 < 97) ? (in - 4 + 26) : (in - 4);
    putchar(in);
}

int main(){
    int in,sleep;
    printf("请输入要解密的句子:");
    sleep = getchar();
    printf("解密文为:");
    decode(sleep);
    while((in = getchar()) != '\n'){
        decode(in);
    }
    printf("\n");
    return 0;
}