#include <stdio.h>
#include <stdlib.h>

//unsigned Fact(unsigned n)
//{
//    unsigned f = 1;
//    for(unsigned i = 1; i <= n; ++i)
//    {
//        f *= i;
//    }
//    return f;
//}

//unsigned Fact(unsigned n)
//{
//    if(n == 1) return 1;
//    return n*Fact(n-1);
//}

//double Expon(double x, unsigned n)
//{
//    if (n == 0) return 1;
//    return x*Expon(x, n-1);
//}

double Expon(double x, unsigned n)
{
    double ex = 1;
    for (unsigned i = 0; i < n; ++i)
    {
        ex *= x;
    }
    return ex;
}

int main()
{
    unsigned a;
    double x = 1.2;
    printf("Please input a positive integer: ");
    scanf("%u",&a);
    printf("\nThe sum of factors (%u) is: %f \n", a, Expon(x, a));
    return 0;
}

