#include <stdio.h>


int main()
{
    char t[7];
    char *c = &t[5];
    int i, j;
    for(i = 0; i < 20; ++i)
    {
        register int p = i;
        for(j = 0; j < 6; ++j)
        {
            t[5-j] = (char)(p % 10 + '0');
            p = p/10;
        }
        t[6] = '\0';
        printf(t);
        printf("\n");
        printf(":%d ", (int)(c-t));
    }

    return 0;
}

