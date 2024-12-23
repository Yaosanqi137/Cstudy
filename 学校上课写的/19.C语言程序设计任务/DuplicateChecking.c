#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// 定义的宏
#define MAX_LEN 4096     // 二元组最大长度
#define SEN_LEN 256      // 最长句长
#define FILES 2          // 总文件数量
#define ALL_KEYWORD 37   // 所有关键词的数量
#define ALL_COMMAND 13   // 所有预处理指令
#define KEYWORD_CODE 1   // 关键字的种别码起始处
#define COMMAND_CODE 38  // 预处理指令种别码起始处
#define NUMBER_CODE 51   // 数字的种别码起始处
#define STRING_CODE 52   // 字符串种别码
#define IDEN_CODE 53     // 标识符种别码

/* 二元组种别码分配
 * 1 ~ 37  - 关键字
 * 38 ~ 50 - 预处理指令
 * 51 ------ 数字
 * 52 ------ 字符串标记
 * 53 ------ 标识符
 * 0 ------- 向量终止符
 * 同时，使用使用二元组进行存储
 * e.g. int main(){printf("helloworld"); return 0;}
 * (4, int), (89, main) ...) */

const char *DATA_OUTPUT = "DATA_OUTPUT.txt"; // 查重模板输出文件夹
const char *CODE_OUTPUT = "CODE_OUTPUT.txt"; // 被查重程序输出文件夹

// 用于存储所有关键字
const char *KEYWORDS[] = {"float", "double", "char", "int", "long", "short",
                    "struct", "union", "enum", "void", "signed", "unsigned", "const",
                    "while", "for", "continue", "break", "if", "else", "do",
                    "goto", "case", "switch", "return", "default", "break",
                    "sizeof", "extern", "register", "static", "auto", "volatile",
                    "inline", "typedef", "_Bool", "_Complex", "_Imaginary",
};

// 用于存储所有预处理指令
const char *COMMANDS[] = {"if", "endif", "include", "define", "error", "else", "ifdef",
                    "ifndef", "undef", "line", "include_next", "pragma", "warning"
};

char DATAFILE[SEN_LEN];                // 数据存放路径
char CHECKFILE[SEN_LEN];               // 被查重代码路径
char BUFFER[SEN_LEN]; // 单句缓冲区
char WORD[SEN_LEN];   // 单词缓冲区

// 用于计算的二元组
typedef struct {
    double code[MAX_LEN];
    char str[MAX_LEN][SEN_LEN];
} TUPLE[FILES];

TUPLE tuples;

// 判断是否为数字
int isNum(char *word){
    if (word[0] >= '0' && word[0] <= '9')
        return 1;
    return 0;
}

// 判断是否为关键字
int isKeyword(char *word){
    for (int i = 0; i < ALL_KEYWORD; i++)
        if (!strcmp(word, KEYWORDS[i]))
            return (KEYWORD_CODE + i) * (KEYWORD_CODE + i);
    return 0;
}

// 判断是否为标识符
int isIdentifier(char *word){
    if(isalpha(word[0]) || word[0] == '_')
        return IDEN_CODE;
    return 0;
}

// 判断是否为预处理指令
int isCommand(char *word){
    for(int i = 0; i < ALL_COMMAND; i++)
        if(!strcmp(word, COMMANDS[i]))
            return COMMAND_CODE + i;
    return 0;
}

// 处理文件，将程序分词，并将其转换成向量
int fileProcessor(FILE *fp, FILE *out, int fileIndex){
    int count = 0, code, inComment = 0, len; // count:记录已录入的词数; code:临时存储判断函数的值; inComment:用于标记是否在多行注释中
    char *start, *ptr; // start:记录数字和单词的起始地址; ptr:指针


    while (fgets(BUFFER, SEN_LEN, fp) != NULL) {
        ptr = BUFFER; // 将指针指向此句句首
        while (*ptr != '\0') {
            if (!strncmp(ptr, "//", 2)) {// 跳过单行注释
                break; // 跳过本行检查
            }if(!strncmp(ptr, "/*", 2)){ // 检测到是多行注释开头，将inComment改为1
                inComment = 1, ptr += 2;
                continue; // 并跳过本次循环
            }if(!strncmp(ptr, "*/", 2)){ // 检查到是多行注释终止符号，将inComment改成0
                inComment = 0, ptr += 2;
                continue; // 并跳过本次循环
            }if(inComment){
                ptr++;
                continue;
            } // 跳过多行注释

            if(isalnum(*ptr) || *ptr == '_'){ // 提取数字和单词
                start = ptr;
                while(isalnum(*ptr) || *ptr == '_')
                    ptr++;
                len = ptr - start;
                strncpy(WORD, start, len); // 将单词和数字拷贝进单词缓冲区
                WORD[len] = '\0';
                // 用于截取数字或关键字或标识符
                code = isKeyword(WORD);
                if(!code && isNum(WORD))
                    code = NUMBER_CODE; // 处理数字
                if(!code)
                    code = isCommand(WORD); // 处理预编译指令
                if(!code)
                    code = isIdentifier(WORD); // 处理标识符
                if(code){
                    tuples[fileIndex].code[count] = code;
                    strcpy(tuples[fileIndex].str[count++], WORD); // 处理关键字、标识符、预处理指令
                    fprintf(out, "%s ", WORD); // 输出到文件
                }
            }else{ // 处理字符串和符号，符号直接丢弃，字符串换成STRING标识
                if(*ptr == '"'){
                    ptr++;
                    while(*ptr != '\"' || *ptr == '\"' && *(ptr - 1) == '\\') // warning! 如果原程序有语法错误，或字符串过长会导致指针越界
                        ptr++;
                    tuples[fileIndex].code[count] = STRING_CODE;
                    strcpy(tuples[fileIndex].str[count++], "STRING");
                    fprintf(out, "%s", "STRING "); // 输出到文件
                }else if(*ptr == '\n')
                    fputc('\n', out);
                ptr++;
            }
        }
    }
    fclose(out);
    fclose(fp);
    return count;
}

double cosSim(double code1[], double code2[], int len1, int len2){
    if(!len2 || !len1)
        return 0;
    double model1 = 0, model2 = 0, product = 0, result;
    // 对向量的每项元素缩减100倍，防止溢出
    for(int i = 0; i < len1; i++)
        code1[i] /= 100;
    for(int i = 0; i < len2; i++)
        code2[i] /= 100;

    int longest = len1 > len2 ? len1 : len2; // 取最长长度，较短向量后补0进行运算

    for(int i = 0; i < longest; i++){
        product += code1[i] * code2[i]; // 求向量积
        model2 += code2[i] * code2[i];  // 求向量模长的平方
        model1 += code1[i] * code1[i];  // 求向量模长的平方
    }

    model2 = sqrt(model2);
    model1 = sqrt(model1);
    result = product / (model2 * model1) * 100; // 计算查重率
    return result;
}

int main(){
    int option; // 选择离开程序还是继续的选项
    printf("**欢迎使用C语言程序查重系统!**\n");
    printf("**注意！请一定要注意原文件语法是否正确，否则本程序无法进行分析**\n");
    do{
        printf("\n请输入第一个代码文件(模板程序)的路径：");
        scanf("%s", DATAFILE);
        printf("\n请输入第二个代码文件(被查重程序)的路径：");
        scanf("%s", CHECKFILE);
        printf("\n**开始对数据进行处理**\n");
        // 程序开始
        FILE *fp = fopen(DATAFILE, "r");
        FILE *outData = fopen(DATA_OUTPUT, "w+");
        int count[FILES];
        if(fp != NULL){
            count[1] = fileProcessor(fp, outData,1);
            printf("%s 已处理\n", DATAFILE);
        }else{
            perror("文件打开失败，请检查文件是否正常!\n");
            return EXIT_FAILURE;
        } // 对查重模板程序进行处理

        fp = fopen(CHECKFILE, "r");
        FILE *outCode = fopen(CODE_OUTPUT, "w+");
        if(fp != NULL){
            count[0] = fileProcessor(fp, outCode,0);
            printf("%s 已处理\n", CHECKFILE);
        }else{
            perror("文件打开失败，请检查文件是否正常!\n");
            return EXIT_FAILURE;
        } // 对被查重程序进行处理

        double result = cosSim(tuples[1].code, tuples[0].code, count[1], count[0]);
        printf("查重成功!结果为: %lf%%\n", result);
        if(result > 50) // 可以在这里设置阈值
            printf("查重率过高，该程序可能存在抄袭现象！\n");
        else
            printf("查重率正常，该程序可能不存在抄袭现象\n");
        // 输出查重结果
        printf("\n请选择是否进行新的查重\n输入\t-\t操作\n====================\n1\t-\t继续\n0\t-\t退出\n选择：");
        scanf("%d", &option);
        putchar('\n');
    }while (option);

    return 0;
}