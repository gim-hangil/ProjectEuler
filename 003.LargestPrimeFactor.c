// Problem 3: Largest Prime Factor
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?
#include <stdio.h>

typedef unsigned long long int llu;

llu target = 600851475143;
llu i;

int main()
{
    while (target > 1)
    {
        for (i = 2; i <= target; i++)
        {
            if (target % i == 0)
            {
                target /= i;
                break;
            }
        }
    }
    printf("%llu\n", i);
    return 0;
}
