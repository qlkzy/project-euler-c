#include <stdio.h>
#include <inttypes.h>

typedef uint64_t u64;


u64 palindromic(u64 base, u64 n)
{
    u64 tmp = n, rev = 0;

    while (tmp) {
        rev *= base;
        rev += tmp % base;
        tmp /= base;
    }
 
    return rev==n ? n : 0;
}

void check(u64 x)
{
    u64 b2, b10;
    b2 = palindromic(2, x);
    b10 = palindromic(10, x);
    if (b2 && b10)
        printf("%" PRIu64 " is palindromic in both bases\n", x);
    else if (b2)
        printf("%" PRIu64 " is only palidromic in base 2\n", x);
    else if (b10)
        printf("%" PRIu64 " is only palindromic in base 10\n", x);
    else
        printf("%" PRIu64 " is palindromic in neither base\n", x);
}

int main()
{
    u64 total = 0;
    for (int i = 0; i < 1000000; i++)
        if (palindromic(2, i) && palindromic(10, i))
            total += i;
    printf("%" PRIu64 "\n", total);
    return 0;
}
