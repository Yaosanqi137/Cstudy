#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// ����ĺ�
#define MAX_LEN 4096     // ��Ԫ����󳤶�
#define SEN_LEN 256      // ��䳤
#define FILES 2          // ���ļ�����
#define ALL_KEYWORD 37   // ���йؼ��ʵ�����
#define ALL_COMMAND 13   // ����Ԥ����ָ��
#define KEYWORD_CODE 1   // �ؼ��ֵ��ֱ�����ʼ��
#define COMMAND_CODE 38  // Ԥ����ָ���ֱ�����ʼ��
#define NUMBER_CODE 51   // ���ֵ��ֱ�����ʼ��
#define STRING_CODE 52   // �ַ����ֱ���
#define IDEN_CODE 53     // ��ʶ���ֱ���

/* ��Ԫ���ֱ������
 * 1 ~ 37  - �ؼ���
 * 38 ~ 50 - Ԥ����ָ��
 * 51 ------ ����
 * 52 ------ �ַ������
 * 53 ------ ��ʶ��
 * 0 ------- ������ֹ��
 * ͬʱ��ʹ��ʹ�ö�Ԫ����д洢
 * e.g. int main(){printf("helloworld"); return 0;}
 * (4, int), (89, main) ...) */

char DATAFILE[200];     // ���ݴ��·��
char CHECKFILE[200];    // �����ش���·��

// ���ڴ洢���йؼ���
char *KEYWORDS[] = {"float", "double", "char", "int", "long", "short",
                    "struct", "union", "enum", "void", "signed", "unsigned", "const",
                    "while", "for", "continue", "break", "if", "else", "do",
                    "goto", "case", "switch", "return", "default", "break",
                    "sizeof", "extern", "register", "static", "auto", "volatile",
                    "inline", "typedef", "_Bool", "_Complex", "_Imaginary",
                    };

// ���ڴ洢����Ԥ����ָ��
char *COMMANDS[] = {"if", "endif", "include", "define", "error", "else", "ifdef",
                    "ifndef", "undef", "line", "include_next", "pragma", "warning"
};

char BUFFER[SEN_LEN];   // ���仺����
char WORD[SEN_LEN];     // ���ʻ�����

// ���ڼ���Ķ�Ԫ��
typedef struct {
    double code[MAX_LEN];
    char str[MAX_LEN][SEN_LEN];
} TUPLE[FILES];

TUPLE tuples;

// �ж��Ƿ�Ϊ����
int isNum(char *word){
    if (word[0] >= '0' && word[0] <= '9')
        return 1;
    return 0;
}

// �ж��Ƿ�Ϊ�ؼ���
int isKeyword(char *word){
    for (int i = 0; i < ALL_KEYWORD; i++)
        if (!strcmp(word, KEYWORDS[i]))
            return (KEYWORD_CODE + i) * (KEYWORD_CODE + i);
    return 0;
}

// �ж��Ƿ�Ϊ��ʶ��
int isIdentifier(char *word){
    if(isalpha(word[0]) || word[0] == '_')
        return IDEN_CODE;
    return 0;
}

int isCommand(char *word){
    for(int i = 0; i < ALL_COMMAND; i++)
        if(!strcmp(word, COMMANDS[i]))
            return COMMAND_CODE + i;
    return 0;
}

// �����ļ���������ִʣ�������ת��������
int fileProcessor(FILE *fp, int fileIndex){
    int count = 0, code, inComment = 0, len; // count:��¼��¼��Ĵ���; code:��ʱ�洢�жϺ�����ֵ; inComment:���ڱ���Ƿ��ڶ���ע����
    char *start, *ptr; // start:��¼���ֺ͵��ʵ���ʼ��ַ; ptr:ָ��; symbol: ���ڴ洢���ţ����ڻ�ɾ��

    while (fgets(BUFFER, SEN_LEN, fp) != NULL) {
        ptr = BUFFER; // ��ָ��ָ��˾����
        while (*ptr != '\0') {
            if (!strncmp(ptr, "//", 2)) {// ��������ע��
                break; // �������м��
            }if(!strncmp(ptr, "/*", 2)){ // ��⵽�Ƕ���ע�Ϳ�ͷ����inComment��Ϊ1
                inComment = 1, ptr += 2;
                continue; // ����������ѭ��
            }if(!strncmp(ptr, "*/", 2)){ // ��鵽�Ƕ���ע����ֹ���ţ���inComment�ĳ�0
                inComment = 0, ptr += 2;
                continue; // ����������ѭ��
            }if(inComment){
                ptr++;
                continue;
            } // ��������ע��

            if(isalnum(*ptr) || *ptr == '_'){ // ��ȡ���ֺ͵���
                start = ptr;
                while(isalnum(*ptr) || *ptr == '_')
                    ptr++;
                len = ptr - start;
                strncpy(WORD, start, len); // �����ʺ����ֿ��������ʻ�����
                WORD[len] = '\0';
                // ���ڽ�ȡ���ֻ�ؼ��ֻ��ʶ��
                code = isKeyword(WORD);
                if(!code && isNum(WORD))
                    code = NUMBER_CODE; // ��������
                if(!code)
                    code = isCommand(WORD);
                if(!code)
                    code = isIdentifier(WORD); // �����ʶ��
                if(code){
                    tuples[fileIndex].code[count] = code;
                    strcpy(tuples[fileIndex].str[count++], WORD); // ����ؼ��֡���ʶ����Ԥ����ָ��
                    // fprintf(output, "%s", WORD); // ������ļ�
                }
            }else{ // �������
                if(*ptr == '"'){
                    ptr++;
                    while(*ptr != '\"' || *ptr == '\"' && *(ptr - 1) == '\\') // warning! ���ԭ�������﷨���󣬻��ַ��������ᵼ��ָ��Խ��
                        ptr++;
                    tuples[fileIndex].code[count] = STRING_CODE;
                    strcpy(tuples[fileIndex].str[count++], "STRING");
                }
                ptr++;
            }
        }
    }
    return count;
}

double cosSim(double code1[], double code2[], int len1, int len2){
    if(!len2 || !len1)
        return 0;
    double model1 = 0, model2 = 0, product = 0, result;

    for(int i = 0; i < len1; i++)
        code1[i] /= 100;
    for(int i = 0; i < len2; i++)
        code2[i] /= 100;

    int longest = len1 > len2 ? len1 : len2;

    for(int i = 0; i < longest; i++){
        product += code1[i] * code2[i];
        model2 += code2[i] * code2[i];
        model1 += code1[i] * code1[i];
    }

    model2 = sqrt(model2);
    model1 = sqrt(model1);
    result = product / (model2 * model1) * 100;
    return result;
}

int main() {
    int option;
    do
    {
        printf("�������һ�������ļ���·����");
        scanf("%s", DATAFILE);
        printf("������ڶ��������ļ�(�������ļ�)��·����");
        scanf("%s", CHECKFILE);
        printf("**ע�⣡��һ��Ҫע��ԭ�ļ��﷨�Ƿ���ȷ�����򱾳����޷����з���**\n");
        printf("**��ʼ�����ݽ��д���**\n");
        // ����ʼ
        FILE *fp = fopen(DATAFILE, "r");
        int count[FILES];
        if(fp != NULL){
            count[1] = fileProcessor(fp, 1);
            fclose(fp);
            printf("%s �Ѵ���\n", DATAFILE);
        }else{
            perror("�ļ���ʧ�ܣ������ļ��Ƿ�����!\n");
            return EXIT_FAILURE;
        } // ��ԭ������д���

        fp = fopen(CHECKFILE, "r");
        if(fp != NULL){
            count[0] = fileProcessor(fp, 0);
            fclose(fp);
            printf("%s �Ѵ���\n", CHECKFILE);
        }else{
            perror("�ļ���ʧ�ܣ������ļ��Ƿ�����!\n");
            return EXIT_FAILURE;
        } // �Ա����س�����д���

        double result = cosSim(tuples[1].code, tuples[0].code, count[1], count[0]);
        printf("���سɹ�!���Ϊ: %lf%%\n", result);
        if(result > 50)
            printf("�����ʹ��ߣ��ó�����ܴ��ڳ�Ϯ����\n");
        else
            printf("�������������ó�����ܲ����ڳ�Ϯ����\n");
        // ������ؽ��
        printf("\n��ѡ���Ƿ�����µĲ���\n����\t-\t����\n====================\n1\t-\t����\n0\t-\t�˳�\nѡ��");
        scanf("%d", &option);
        putchar('\n');
    } while (option == 1);

    return 0;
}
