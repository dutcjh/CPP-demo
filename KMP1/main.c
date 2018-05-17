#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 1000000001


int main()
{
    clock_t start, finish;
    char *pi1b, *c;
    char t[7];
    pi1b = (char *)malloc(sizeof(char)*MAXNUM);
    register char ch;
    register int i = 0, j = 0;
    FILE *fp = fopen("pi1b.txt", "r");
    if (fp == NULL)
        return 0;
    while((ch= fgetc(fp)) != EOF)
    {
        pi1b[i] = ch;
        ++i;
    }
    pi1b[i] = '\0';
    fclose(fp);
    start = clock();
    for(i = 0; i < 10000; ++i)
    {
        register int p = i;
        for(j = 0; j < 6; ++j)
        {
            t[5-j] = (char)(p % 10 + '0');
            p = p/10;
        }
        t[6] = '\0';
        c = strstr(pi1b, t);
        if(i % 1000 == 0)
        {
            printf(t);
            printf(":%d \n", (int)(c-pi1b));
        }
    }
    free(pi1b);
    finish = clock();
    printf("\nThe run time is: %f s.\n", (double)(finish-start)/CLOCKS_PER_SEC);
    return 0;
}
