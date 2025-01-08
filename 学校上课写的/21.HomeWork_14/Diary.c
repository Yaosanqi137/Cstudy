// 10.12
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 256 // 缓冲区大小

// 各种常量以及缓冲区
const char *DIARY_FILE = ".\\D\\diary\\today.txt";

const char *BACKUP_FILE = ".\\E\\backup\\backup.dat";

const char *HISTORY_FILE = ".\\D\\diary\\history.txt";

char buffer[MAX_LEN];

// 文件复制函数
int fileCopy(FILE *from, FILE *to){
    char ch;
    if(from == NULL || to == NULL)
        return EXIT_FAILURE;
    while((ch = fgetc(from)) != EOF)
        fwrite(&ch, sizeof(char), 1, to);
    fclose(from);
    fclose(to);
    return EXIT_SUCCESS;
}

// 文本插入函数
int fileInsert(FILE *from, FILE *to){
    char ch;
    if(from == NULL || to == NULL)
        return EXIT_FAILURE;
    while((ch = fgetc(from)) != EOF)
        fputc(ch, to);
    fputc('\n', to);
    fclose(from);
    fclose(to);
    return EXIT_SUCCESS;
}

int main(){
    printf("正在打开日记...\n");
    FILE *fp = fopen(DIARY_FILE, "r+");
    FILE *his = fopen(HISTORY_FILE, "a+");
    if(fp == NULL){
        perror("日记文件无法正常打开");
        exit(EXIT_FAILURE);
    }else
        printf("正在写日记...\n");
    fileInsert(fp, his);
    while(fgets(buffer, MAX_LEN, fp) != NULL)
        printf("%s", buffer);
    printf("日记保存成功!\n");
    fclose(fp);
    // 写日记并将内容输出

    printf("正在删除backuo.dat并重新将history.txt中的内容复制到backup.dat中\n");
    FILE *from, *to;
    from = fopen(HISTORY_FILE, "r");
    to = fopen(BACKUP_FILE, "w+");
    if(!fileCopy(from, to))
        printf("复制成功!\n");
    else{
        perror("复制失败");
        exit(EXIT_FAILURE);
    }
    // 将history.txt中的内容复制到backup.dat

    return EXIT_SUCCESS;
}