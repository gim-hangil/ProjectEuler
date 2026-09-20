// Problem 6: Sum Square Difference
//
// The sum of the squares of the first ten natural numbers is,
//
// 1 ^ 2 + 2 ^ 2 + ... + 10 ^ 2 = 385.
//
// The square of the sum of the first ten natural numbers is,
//
// (1 + 2 + ... + 10) ^ 2 = 55 ^ 2 = 3025.
//
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 - 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.

#include <stdio.h>

const int N = 100;
int i, sqaureSum, sumSquare;

int main()
{
    sqaureSum = 0;
    for (i = 1; i <= N; i++)
    {
        sqaureSum += i * i;
    }

    sumSquare = (N + 1) * N / 2;
    sumSquare *= sumSquare;

    printf("%d\n", sumSquare - sqaureSum);
    return 0;
}
