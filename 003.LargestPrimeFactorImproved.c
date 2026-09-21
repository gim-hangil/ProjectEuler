// Problem 3: Largest Prime Factor
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?
#include <stdio.h>
#include <math.h>

typedef unsigned long long int llu;

llu target = 600851475143;
llu factor, prev_factor, prime_limit;

int main()
{
    prev_factor = 1;
    while (target % 2 == 0)  // 2 is special since it is the only even prime
    {
        target /= 2;
        prev_factor = 2;
    }

    factor = 3;
    prime_limit = (int) sqrt(target);
    while (target > 1 && factor <= prime_limit)
    {
        while (target % factor == 0)
        {
            target /= factor;
            prev_factor = factor;
        }
        prime_limit = (int) sqrt(target);
        factor += 2;
    }
    
    if (target == 1)
    {
        printf("%llu\n", prev_factor);
    }
    else
    {
        printf("%llu\n", target);
    }
    return 0;
}
