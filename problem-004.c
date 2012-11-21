/* Solution to Project Euler Problem 4 */
/* Finding the largest palindrome made from the product of 2 3-digit
 * numbers */
#include <stdio.h>

int is_palindrome(int x)
{
    int digits[6] = {0};        /* 999*999 => 6 digits */
    int *up, *pd;
    up = pd = digits;
    while (x) {
        *up++ = x % 10;
        x /= 10;
    }
    while (*(--up) == *pd++ &&
           up >= pd)
        ;
    return up < pd;
}

int max(x,y) {return x > y ? x : y;}

int main()
{
    int i, j;
    int result = 0;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 1000; j++)
            if (is_palindrome(i*j))
                result = max(result, i*j);
    printf("%d\n", result);
    return 0;
}
