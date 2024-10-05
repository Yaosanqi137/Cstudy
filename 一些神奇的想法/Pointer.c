// 哈哈哈，我在学指针怎么用
#include <stdio.h>

void eg1(){
    char str[] = "Hello";
    char *ptr = str; // 把仁兄的地址交给你了哈
    printf("%llu byte\n", sizeof(str)); // 看看这个数组所占的字节(btye)数,一个 char 就占一个,而这里有 5 项，再加上看不到的 EOF 字符，就是 6 个字符，这里会输出 6 byte
    for(int i = 0;str[i];i++){
        (*ptr) += 1; // 把仁兄这段地址的值加个十进制的1(人话:数组这一项对应的字符的ASCII码+1)
        printf("%c ", *ptr); // 但是要注意的是,str[]对应的这一项的值并没有变，只是 *ptr 值的变了而已
        (*ptr)--;
        printf("%p\n", ptr); // 把仁兄开盒了😅家庭住址都爆出来了
        ptr++; // 把指针的位置往下移一位，也就是移动到数组后一项
    }
    ptr = str;
    for(int i = 0;str[i];i++){
        printf("%c ", *ptr);
        printf("%p\n", ptr);
        ptr++;
    }
}

int main(){
    eg1();
}
