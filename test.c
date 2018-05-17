#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;
    scanf("%lf",&x);
    y = (exp(x)+exp(-x))/2;
    printf("y = %lf\n",y);
    system("pause");
    return 0;
}
