#include <stdio.h>

int main(){
    printf("请输入你想要转换为十六进制的十进制数：");
    int DEC,neige_A;
    scanf("%d", &DEC);
    int HEX[64];
    int neige_B = 0;

    do{
        neige_A = DEC % 16;
        DEC /= 16;
        HEX[neige_B++] = neige_A; //将每一位得出的余数都存储到数组中
    }while(neige_A == DEC);
    neige_B -= 1;
    for(;neige_B >= 0;neige_B--){ //反向输出数组
        switch(HEX[neige_B]){ //将每一位余数输出为对应的16进制数
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", HEX[neige_B]);
                break;
        }
    }
    printf("\n转换成功!");
    return 0;
}