/* Solution to Project Euler Problem 3 */
/* Finding the Largest Prime Factor of 600851475143 */
#include <stdio.h>

int main()
{
    long long num = 600851475143LL;
    long fac = 1;
    while (num > 1) {
        fac++;
        while (num % fac == 0)
            num /= fac;
    }
    printf("%d\n", fac);
    return 0;
}
