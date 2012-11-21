/* Finding the difference between the sum of the squares and the
 * square of the sums of the first 100 natural numbers */
#include <stdio.h>

int main()
{
    int sumsq = 0, sum = 0, i;
    for (i = 1; i <= 100; i++) {
        sumsq += i*i;
        sum += i;
    }
    printf("%d\n", sum*sum - sumsq);
    return 0;
}
