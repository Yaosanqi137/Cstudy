// 参照的C语言标准: C99
// 引用的头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 定义的宏
#define MAX_LEN 4096     // 二元组最大长度
#define SEN_LEN 256      // 最长句长
#define FILES 2          // 总文件数量
#define ALL_KEYWORD 37   // 所有关键词的数量
#define ALL_SYMBOL 27    // 所有运算符、界限符和逻辑符
#define ALL_COMMAND 13   // 所有预编译指令
#define NUMBER 10        // 所有数字
#define KEYWORD_CODE 1   // 关键字的种别码起始处
#define SYMBOL_CODE 38   // 各种符号的种别码起始处
#define NUMBER_CODE 65   // 数字的种别码起始处
#define COMMAND_CODE 75  // 预编译指令的种别码起始处
#define STRING_CODE 88   // 字符串种别码
#define STRUCT_CODE 89   // 标识符种别码
#define OTHER_CODE 93    // 预编译指令或其他的标识符种别码

/* 二元组种别码分配
 * 1 ~ 37  - 关键字
 * 38 ~ 64 - 各种符号
 * 65 ~ 74 - 数字
 * 75 ~ 87 - 预编译指令
 * 88 ------ 字符串标记
 * 89 ------ 标识符
 * 0 ------- 向量终止符
 * 同时，使用使用二元组进行存储
 * e.g. int main(){printf("helloworld"); return 0;}
 * (4, int), (89, main) ...) */

// 数据存放路径
const char *DATAFILE = "Data.c";

// 被查重代码路径
const char *CHECKFILE = "TestCode.c";

// 用于存储所有运算符和分界符
char *SYMBOLS[] = {"+", "-", "*", "/", "%", "=", "<", ">", ">=", "<=",
                    "!=", "==", ";", ":", "[", "]", "{", "}", "(", ")",
                   "&", "|", ",", "'", "\"", "!", ".",
                    };

// 用于存储所有关键字
char *KEYWORDS[] = {"float", "double", "char", "int", "long", "short",
                    "struct", "union", "enum", "void", "signed", "unsigned", "const",
                    "while", "for", "continue", "break", "if", "else", "do",
                    "goto", "case", "switch", "return", "default", "break",
                    "sizeof", "extern", "register", "static", "auto", "volatile",
                    "inline", "typedef", "_Bool", "_Complex", "_Imaginary",
                    };

// 用于存储所有预编译指令
char *COMMANDS[] = {"if", "endif", "include", "define", "error", "else", "ifdef",
                      "ifndef", "undef", "line", "include_next", "pragma", "warning"
                    };

// 缓冲区
char *buffer;

// 单字最长长度
char *word_A, *word_B, *word_C;

// 用于计算的二元组
typedef struct {
    int code[MAX_LEN];
    char str[MAX_LEN];
} TUPLE[FILES];

int isNum(char *words){
    if(words[0] >= '0' && words[0] <= '9')
        return 1;
    return 0;
}

/* TODO
 * 余弦相似度计算函数 */
double cosCalculate(){

}

/* TODO
 * 比较函数
 * 使用生成好的向量计算查重 */
void compare(){

}

/* TODO
 * 处理文件，将程序转换成向量 */
void fileProcessor(FILE *fp){
    int count = 0;
    while(fgets(buffer, SEN_LEN, fp) != NULL){
        word_A = strtok(buffer, " \t\n");
        while(word_A != NULL){
            printf("%s\n\n", word_A);

            word_B = word_A;
            strchr(word_B, );
            while(*word_B != '\0'){

                word_B++;
            }

            word_A = strtok(NULL, " \t\n");
            count++;
        }
    }
}

int main(){
    printf("**请将模板C语言程序放在data文件夹内，被查重的程序放在check文件夹内**\n");
    printf("**开始对数据进行处理**\n");
    // 程序初始输出
    FILE *fp = NULL;
    fp = fopen(DATAFILE, "r");
    if(fp != NULL){
        fileProcessor(fp);
        if(fclose(fp)){
            perror("文件无法正常关闭！\n");
            return EXIT_FAILURE;
        }else
            printf("文件已关闭\n");
    }else{
        perror("文件打开失败，请检查文件是否正常或Data.c文件是否存在!\n");
        return EXIT_FAILURE;
    }
    return 0;
}