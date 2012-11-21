/* find the value of the first triangle number to have over 500 divisors */
#include <stdio.h>


#define LIMIT 2000000

/* complement sense of sieve to take advantage of zero-init */
static int sieve[LIMIT];

void getprimes()
{
    int scan, i;
    long long sum = 0;
    for (i = 2; i*i < LIMIT; ) {
        scan = i;
        while (scan+i < LIMIT)    /* sieve */
            sieve[scan+=i] = 1;
        do i++;
        while (sieve[i]);        /* search */
    }
    for (i = 2; i < LIMIT; i++)
        if (!sieve[i])
            sum += i;
}

int next_triangle()
{
    static int acc = 0;
    static int n = 1;
    return acc += n++;
}

int main()
{
    int tri, ttri, fac, pow;
    int ndivs = 1;
    getprimes();
    while (ndivs <= 500) {
        ttri = tri = next_triangle();
        pow = ndivs = 1;
        fac = 2;
        while (fac < LIMIT) {
            if (ttri % fac == 0) {
                ttri /= fac;
                pow++;
            } else {
                ndivs *= pow;
                pow = 1;
                while (sieve[++fac]) 
                    ;
                if (ttri == 1) break;
            }
        }
    }
    printf("%d (%d divisors)\n", tri, ndivs, pow);
    return 0;
}
