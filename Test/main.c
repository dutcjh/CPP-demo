#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;
    printf("Please input x: \n");
    scanf("%lf",&x); // ��%lf������%f
    y = (exp(x)+exp(-x))/2;
    printf("y = %f\n",y);  // ��%f������%lf
    system("pause");
    return 0;
}
