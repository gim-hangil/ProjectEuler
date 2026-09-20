// Problem 0: Sum of Odd Squares
//
// A number is a perfect square, or a square number, if it is the square of a
// positive integer.
// For example, 25 is a square number because 5 ^ 2 = 5 * 5 = 25; it is also an
// odd square.
//
// The first 5 square numbers are: 1, 4, 9, 16, 25, and the sum of the odd
// squares is 1 + 9 + 25 = 35.
//
// Among the first 739 thousand square numbers, what is the sum of all the odd
// squares?

#include <stdio.h>

const unsigned long long int MAX = 739000;
unsigned long long int n;
unsigned long long int sum;

int main()
{
    sum = 0;
    for (n = 1; n < MAX; n += 2)
    {
        sum += n * n;
    }
    printf("%llu\n", sum);
    return 0;
}
