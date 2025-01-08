// 2021 B
// 题的输入输出好像有点问题
#include <stdio.h>
#include <string.h>
#define DAYS 30
#define MAX_LEN 30

int result[DAYS];

int isLegal(char word[]){
    int check[26] = {0}, len = strlen(word), freq[26] = {0}, count = 0;
    for(int i = 0; i < len; i++)
        check[word[i] - 'a']++;

    for(int i = 0; i < 26; i++)
        if(check[i])
            freq[count++] = check[i];

    for(int i = 0; i < count; i++)
        if(freq[i] == len)
            return 1;

    for(int i = 0; i < count - 1; i++)
        for(int j = i + 1; j < count; j++)
            if(freq[i] == freq[j])
                return 1;
    return 0;
}

int main(){
    int day, words;
    double start, end;
    char word[MAX_LEN];
    scanf("%d", &day);
    for(int i = 0; i < day; i++){
        scanf("%d", &words);
        for(int j = 0; j < words; j++){
            scanf("%s", word);
            if(isLegal(word))
                result[i]++;
        }
    }
    putchar('\n');
    for(int i = 0; i < day; i++)
        printf("Case %d: %d\n", i + 1, result[i]);
    return 0;
}