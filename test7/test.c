#include <stdio.h>
#include <stdlib.h>
int fun(float hpaper, float h)
{
    int n;
    for(n=1; hpaper<=h; n++)
    {
        hpaper = 2*hpaper;
    }
    return n;
}

int main()
{
    float hpaper=0.5, h=2;
    int n=0;
    FILE *fp;
    fp = fopen("Êä³ö.txt","wb+");
    n = fun(hpaper, h);
    fprintf(fp,"%6d\n",n);
    fclose(fp);
    system("pause");
    return 0;
}
