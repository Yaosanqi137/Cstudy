//给定任何数字，我们可以通过添加该数字的数字平方和来创建一个新数字。例如，给定 203，我们的新号码是 4 + 0 + 9 = 13。如果我们重复这个过程，我们会得到一个数字序列：
//203 -> 13 -> 10 -> 1 -> 1
//有时，与 203 一样，序列到达（并停留在）1。像这样的数字被称为快乐。
//
//并不是所有的数字都是快乐的。如果我们从 11 开始，序列将是：
//11 -> 2 -> 4 -> 16 -> ...
//这个序列永远不会到达1，所以这个数字11被称为不快乐。
//
//给定一个正整数，你必须确定这个数字是快乐的还是不快乐的。
#include <stdio.h>

int main(){
    char str[64];
    int term, nums[64];
    scanf("%s", str);
    for(int i = 0; i < 64; i++){
        term = 0;
        for(int n = 0; str[n]; n++){
            term += (str[n] - 48) * (str[n] - 48);
        }
        sprintf(str, "%d", term);
        nums[i] = term;
        printf("%d->", nums[i]);
        if(i > 0){
            if(nums[i - 1] < nums[i]){
                printf("False");
                break;
            }else if(nums[i - 1] == 1 & nums[i] == 1){
                printf("True");
                break;
            }
        }
    }
    return 0;
}