// Problem 5: Smallest Multiple
//
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>

const int N = 20;
int i, num;

int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    num = 1;
    for (i = N; i > 0; i--)
    {
        if (num % i != 0)
        {
            num *= i / gcd(num, i);
        }
    }
    printf("%d\n", num);
    return 0;
}
