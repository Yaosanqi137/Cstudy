#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char arr[] = {'-', '\\', '|', '/'};

int main(){
    #ifdef _WIN32
        system("chcp 65001");
    #endif
    int i = 0;
    double m = 0;
    srand(time(NULL));
    while(m <= 1){
        printf("\033[G");
        printf("Processing... \033[32m%c\033[0m ", arr[(i++ % 4)]);
        printf("[\033[34;40m ");
        for(int k = 0; k < 50; k++)
            if(k < m * 50)
                printf("█");
            else
                putchar(' ');
        printf("  \033[0m] %.2lf%%", m * 100);
        m += (rand() % 20) / 1000.0;
        fflush(stdout);
        usleep(100000);
    }
    printf("\033[G");
    printf("Processing... \033[32m%c\033[0m ", arr[(i % 4)]);
    printf("[\033[31;40m ");
    for(int k = 0; k <= 50; k++)
        if(k < m * 50)
            printf("█");
        else
            putchar(' ');
    printf(" \033[0m] %.2lf%%", 100.00);
    printf("\nDone!\n");
    #ifdef _WIN32
        system("pause");
    #else
        system("read -n 1 -s");
    #endif
    return 0;
}