// 参照的C语言标准: C99
// 引用的头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 定义的宏
#define ALL_KEYWORD 37  // 所有关键词的数量
#define DATAFILES 16    // 最大数据文件量
#define ALL_SYMBOL 27   // 所有运算符、界限符和逻辑符
#define ALL_COMMAND 13  // 所有预编译指令
#define NUMBER 10       // 所有数字
#define KEYWORD_CODE 0  // 关键字的种别码起始处
#define SYMBOL_CODE 37  // 各种符号的种别码起始处
#define NUMBER_CODE 64  // 数字的种别码起始处
#define COMMAND_CODE 74 // 预编译指令的种别码起始处
#define STRING_CODE 87  // 字符串种别码
#define STRUCT_CODE 88  // 结构体种别码
#define FUNC_CODE 89    // 函数种别码
#define ENUM_CODE 90    // 枚举种别码
#define HEADER_CODE 91  // 头文件种别码
#define OTHER_CODE 92   // 预编译指令或其他的标识符种别码
#define MAX_LEN 4096    // 二元组最长长度



/*二元组种别码分配
 * 0 ~ 36  - 关键字
 * 37 ~ 63 - 各种符号
 * 64 ~ 73 - 数字
 * 74 ~ 86 - 预编译指令
 * 87 ------ 字符串标记
 * 88 ------ 结构体标记
 * 89 ------ 函数标记
 * 90 ------ 枚举标记
 * 91 ------ 头文件标记
 * 92 ------ 预编译指令或其他的标识符
 * 同时，使用二元组进行存储
 * e.g. int main(){printf("helloworld"); return 0;}
 * (3, "int"), (89, "main"), ... */



// 数据存放路径
char *DATA_ADDR = "/data/";

// 被查重代码路径
char *CHECKFILE = "/check/";

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
char *COMMANDS[] = {"#if", "endif", "#include", "#define", "#error", "#else", "#ifdef",
                      "ifndef", "#undef", "#line", "#include_next", "#pragma", "#warning"
                    };

struct Tuple { // 二元组
    int count;
    char *word;
} TUPLE[MAX_LEN];

void compare(){

}

void fileProcessor(){

}

int main(){
    printf("**请将模板C语言程序放在data文件夹内，被查重的程序放在check文件夹内**\n");
    printf("**开始对数据进行处理**");
}