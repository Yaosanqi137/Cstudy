// 6.17
#include <stdio.h>
#include <string.h>

void swap(char str1[], char str2[]){
    char temp[10];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void strSort(char str[][10], int length){
    int key;
    for(int n = 0; n < length; n++){
        key = n;
        for(int j = n; j < length; j++){
            if(strcmp(str[j], str[key]) < 0){
                key = j;
            }
        }
        swap(str[key], str[n]);
    }
}

int main(){
    char str[][10] = {"China", "USA", "England", "Russia"};
    printf("原始数据为:\n");
    for(int i = 0; i < 4; i++)
        printf("%s\n", str[i]);
    printf("排序结果为:\n");
    strSort(str, 4);
    for(int i = 0; i < 4; i++)
        printf("%s\n", str[i]);
    return 0;
}
