/* Finding the smallest positive number evenly divisible by all of the
 * numbers 1 to 20 */
#include <stdio.h>

int main()
{
    int i, j;
    for (i = 20; ; i += 20) {
        for (j = 1; j <= 20; j++)
            if (i % j != 0)
                goto cont;
        break;
    cont:
        continue;
    }
    printf("%d\n", i);
    return 0;
}
