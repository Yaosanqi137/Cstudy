// 10.12
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 256 // 缓冲区大小

// 各种常量以及缓冲区
const char *DIARY_FILE = ".\\D\\diary\\today.txt";

const char *BACKUP_FILE = ".\\E\\backup\\backup.dat";

const char *HISTORY_FILE = ".\\D\\diary\\history.txt";

const char *weather[] = {"多云", "晴", "雨", "雪", "下冰雹", "核辐射", "伽马射线暴"};

const char *context[] = {
        "　　我去，今天有点走运，在路上捡到10块钱哈哈哈！\n但是可惜的是，我不小心掉水沟里了嘤嘤嘤。\n",
        "　　他妈的，什么玩意，就放三天假，怎么布置了那么多作业？气死爷了。\n回去打游戏摆烂算了。\n",
        "　　嘿嘿嘿，今天遇到初音未来了，还跟她合照了。不愧是我。\n话说今天晚上吃什么？\n",
        "　　今天天气真好，出去散步的时候遇到了一只可爱的小狗。\n可惜它跑得太快，没来得及摸摸它。\n",
        "　　今天考试考砸了，心情有点低落。\n不过没关系，下次再努力吧！\n",
        "　　今天在图书馆看书，突然发现了一本超级有趣的书。\n一口气看了好几个小时，完全停不下来。\n",
        "　　今天和朋友一起去吃了火锅，辣得我直冒汗。\n不过味道真的太棒了，下次还要再来！\n",
        "　　今天在公交车上遇到了一个老奶奶，主动让座给她。\n她笑着对我说谢谢，感觉自己做了件好事。\n",
        "　　今天收到了一份意外的礼物，开心得不得了。\n原来是我生日快到了，朋友提前准备的惊喜。\n",
        "　　今天去爬山，虽然很累，但风景真的很美。\n站在山顶的感觉，简直太棒了！\n"
};


char buffer[MAX_LEN];

// 写日记函数
void diary(FILE *fp){
    int temp1 = rand() % 7, temp2 = rand() % 10;
    fprintf(fp, "日期: %s  天气: %s\n", __DATE__, *(weather + temp1));
    fputs(*(context + temp2), fp);
    fputc('\n', fp);
    rewind(fp);
}

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
    fclose(from);
    fclose(to);
    return EXIT_SUCCESS;
}

int main(){
    srand(time(NULL));
    printf("正在打开日记...\n");
    FILE *fp = fopen(DIARY_FILE, "w+");
    if(fp == NULL){
        perror("日记文件无法正常打开");
        exit(EXIT_FAILURE);
    }else
        printf("正在写日记...\n\n");
    diary(fp);
    while(fgets(buffer, MAX_LEN, fp) != NULL)
        printf("%s", buffer);
    fclose(fp);
    // 写日记并将内容输出

    printf("正在删除backup.dat文件...\n");
    if(!remove(BACKUP_FILE))
        printf("删除成功!\n");
    else{
        perror("删除失败");
        exit(EXIT_FAILURE);
    }
    // 删除backup.dat文件

    printf("正在将history.txt中的内容复制到backup.dat中\n");
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

    FILE *source, *insert;
    printf("正在将today.txt中的内容插入到history.txt中...\n");
    source = fopen(DIARY_FILE, "r");
    insert = fopen(HISTORY_FILE, "a+");
    if(!fileInsert(source, insert))
        printf("插入成功!\n");
    else{
        perror("插入失败");
        exit(EXIT_FAILURE);
    }
    // 将today.txt中的内容插入到history.txt中

    return EXIT_SUCCESS;
}