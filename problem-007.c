/* Finding the 10001st prime */
#include <stdio.h>

#define NPRIMES 10001

int main()
{
    int primes[NPRIMES] = {2, 3, 0};
    int i, j, k;
    for (i = 2; i < NPRIMES; i++) {
        for (j = primes[i-1]; ; j++) {
            for (k = 0; k < i; k++)
                if (j % primes[k] == 0)
                    goto cont;
            break;
        cont:
            continue;
        }
        primes[i] = j;
    }
    return 0;
}
