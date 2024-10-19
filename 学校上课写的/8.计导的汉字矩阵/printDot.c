// 使用的时候注意编码
// 请使用 gbk 或 gb2312
#include "stdio.h"
#include "stdlib.h"

const int REG_LEN = 94;           // 每区(行)有 94 位(列)
const int FONT_WEIGHT  = 16;      // 单字点阵宽度(列数)
const int FONT_HEIGHT = 16;       // 单字点阵高度(行数)
const int DOT_SIZE = 16 * 16 / 8; // 一个汉字点阵所占的字节数
const int SUB_CODE = 0xA0;        // 内码与区、位码的差值

char *FONT_FILE_NAME = "chs16.fon"; // 点阵字库文件名
char BIN_DOT[16 * 16 / 8] = {0};    // 存储点阵信息的数组

// 按顺序输出点阵的每一位信息
void printCharBinDot(char* binDot, int len)
{
    int bitNum = 0;  // 已读取的位数
    int bitIndex =0; // 当前位号
    int bitValue;    // 当前位的值
    int charNum;     // 当前字节号
    for (charNum =0; charNum < len; ++charNum)
    {
        // 从高到低顺次输出一个字节的每位信息
        for(bitIndex = 7; bitIndex >= 0; --bitIndex)
        {
            // 输出当前字节第 bitIndex 位的值
            bitValue  = ((binDot[charNum] >> bitIndex) & 0x1 );
            printf("%c ", bitValue + 'H');

            // 满 12 位输出一行
            if ((++bitNum % 16) == 0)
                printf("\n");
        }
    }
}

int main()
{
    FILE *fp = fopen(FONT_FILE_NAME, "rb");
    int stringSize = FONT_WEIGHT * FONT_HEIGHT;
    // 输入模块
    int byte;
    printf("请问你想要输入几个字:");
    scanf("%d", &byte);
    byte = byte * 2 + 1;
    char *STR = (char *)malloc(byte);
    getchar();
    printf("请输入句子: ");
    fgets(STR, byte, stdin);

    int i = 0;
    int offset = 0;
    unsigned char regCode; // 区码
    unsigned char bitCode; // 位码

    for(;STR[i];i+=2){
        // 计算区位码，
        regCode = (unsigned char)STR[i] - SUB_CODE;
        bitCode = (unsigned char)STR[i + 1] - SUB_CODE;
        // 再计算汉字在字库中的位置，进而得出此字符点阵在字体文件中的偏移
        offset = ((regCode - 1) * REG_LEN + bitCode - 1) * DOT_SIZE;

        // 在字库文件中读取其点阵数据
        fseek(fp, offset, SEEK_SET);
        fread(BIN_DOT, sizeof(BIN_DOT), 1, fp);

        //输出其点阵信息
        printCharBinDot(BIN_DOT, DOT_SIZE);
        printf("\n");
    }

    fclose(fp);
    free(STR);
    system("pause");
    return 0;
}

