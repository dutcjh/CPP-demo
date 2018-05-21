#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;
    printf("Please input x: \n");
    scanf("%lf",&x); // 用%lf不能用%f
    y = (exp(x)+exp(-x))/2;
    printf("y = %f\n",y);  // 用%f不能用%lf
    system("pause");
    return 0;
}
