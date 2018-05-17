#include <stdio.h>
#include <stdlib.h>

unsigned sum_factors(unsigned n)
{
    unsigned sum = 0;
    for(unsigned i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    unsigned a;
    printf("Please input a positive integer: ");
    scanf("%u",&a);
    printf("\nThe sum of factors (%u) is: %u \n", a, sum_factors(a));
    return 0;
}
