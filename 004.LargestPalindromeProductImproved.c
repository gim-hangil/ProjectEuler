// Problem 4: Largest Palindrome Product
//
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 * 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>

int a, b, delta, maxPalindrome = 0;

bool isPalindrome(int n)
{
    int reversed = 0, original = n;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int main()
{
    for (a = 999; a >= 100; a--)
    {
        // a or b must be divisible by 11
        // 6 digit palindrome P = xyzzyx = 100001x + 10010y + 1100z = 11(9091x + 910y + 100z)
        if (a % 11 == 0)
        {
            b = 999;
            delta = 1;
        }
        else
        {
            b = 990;
            delta = 11;
        }
        for (b = 999; b >= a; b -= delta)
        {
            if (a * b <= maxPalindrome)
            {
                break;
            }
            if (isPalindrome(a * b))
            {
                maxPalindrome = a * b;
            }
        }
    }

    printf("%d\n", maxPalindrome);

    return 0;
}
