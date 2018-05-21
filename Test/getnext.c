#include <stdio.h>
#include <string.h>

void get_next(const char *T, int *next)
{
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0])
    {
        if (j==0 || T[i]==T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}


int main()
{
    const char *s = "abcabx";
    int next[7] = {0,0,0,0,0,0,0};
    get_next(s,next);
    int i;
    for(i=0;i<6;++i)
        printf("%d", next[i]);
    return 0;
}
