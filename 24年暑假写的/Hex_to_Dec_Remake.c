#include <stdio.h>
#include <math.h>
#include <string.h>

//int main(){
//    printf("请输入一个十六进制数");
//    char HEX[64];
//    int neige_A = 0;
//    for(;;neige_A++){
//        printf("\n请输入第%d位: ", neige_A + 1);
//        scanf("%c", &HEX[neige_A]);
//        printf("\nget到了,继续吧!如果想终止,请输入K");
//        getchar();
//        if(HEX[neige_A] == 'K'){
//            break;
//        }
//    }
//
//    int neige_C = 0;
//    neige_A -= 1;
//    int DEC[64];
//    for(;neige_A >= 0;neige_A--){
//        if(HEX[neige_A] == 'A'){
//            DEC[neige_C] = 10;
//        }else if(HEX[neige_A] == 'B'){
//            DEC[neige_C] = 11;
//        }else if(HEX[neige_A] == 'C'){
//            DEC[neige_C] = 12;
//        }else if(HEX[neige_A] == 'D'){
//            DEC[neige_C] = 13;
//        }else if(HEX[neige_A] == 'E'){
//            DEC[neige_C] = 14;
//        }else if(HEX[neige_A] == 'F'){
//            DEC[neige_C] = 15;
//        }else if(HEX[neige_A] == '1'){
//            DEC[neige_C] = 1;
//        }else if(HEX[neige_A] == '2'){
//            DEC[neige_C] = 2;
//        }else if(HEX[neige_A] == '3'){
//            DEC[neige_C] = 3;
//        }else if(HEX[neige_A] == '4'){
//            DEC[neige_C] = 4;
//        }else if(HEX[neige_A] == '5'){
//            DEC[neige_C] = 5;
//        }else if(HEX[neige_A] == '6'){
//            DEC[neige_C] = 6;
//        }else if(HEX[neige_A] == '7'){
//            DEC[neige_C] = 7;
//        }else if(HEX[neige_A] == '8'){
//            DEC[neige_C] = 8;
//        }else if(HEX[neige_A] == '9'){
//            DEC[neige_C] = 9;
//        }
//        neige_C++;
//    }
//
//    neige_C -= 1;
//    int total = 0;
//    for(;neige_A <= neige_C;neige_A++){
//        total += DEC[neige_A]*pow(16,neige_A);
//    }
//    printf("\n结果为:%d", total);
//    return 0;
//}
// 上面那坨是屎山，不要用，用这里的
// 这里的版本得是 Re-remake 了哈哈哈，因为之前还有个更加屎山的

int main(){
    long long Dec = 0;
    char Hex[16];
    printf("请输入一个十六进制数(不超过 15 位):");
    fgets(Hex, 16, stdin); // 只会截取前面 15 位，后面的会自动断掉滴
    char *ptr = Hex;
    ptr += strlen(Hex) - 2;
    Hex[strlen(Hex) - 1] = '\0'; // 妈妈生的，最后一个元素是'\n'，再后面才是EOF
    for(int i = 0;Hex[i];i++) {
        if ((*ptr) == 48 && i == 0){
            break;
        }else if(49 <= (*ptr) && (*ptr) <= 57){
            Dec += ((*ptr) - 48) * (long long)pow(16, i);
        }else if(65 <= (*ptr) && (*ptr) <= 70){
            Dec += ((*ptr) - 55) * (long long)pow(16, i);
        }else{
            printf("警告!错误的输入,程序已退出");
            return 1;
        }
        ptr--;
    }
    printf("对应十进制数为: %lld\n", Dec);
    return 0;
} // 这才比较好吧
