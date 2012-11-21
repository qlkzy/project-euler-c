#include <stdio.h>

int main()
{
    int total = 0;
    int next, curr, prev;
    prev = curr = 1;
    while (curr <= 4000000) {
        next = prev + curr;
        if (curr % 2 == 0)
            total += curr;
        prev = curr;
        curr = next;
    }
    printf("%d\n", total);
}
