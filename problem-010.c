/* Summing all the primes below two million */
#include <stdio.h>

#define LIMIT 2000000

/* complement sense of sieve to take advantage of zero-init */
static int sieve[LIMIT];

int main()
{
    int scan, i;
    long long sum = 0;
    for (i = 2; i*i < LIMIT; ) {
        printf("prime: %d\n", i);
        scan = i;
        while (scan+i < LIMIT)    /* sieve */
            sieve[scan+=i] = 1;
        do i++;
        while (sieve[i]);        /* search */
    }
    for (i = 2; i < LIMIT; i++)
        if (!sieve[i])
            sum += i;
    printf("%lld\n", sum);
    return 0;
}
