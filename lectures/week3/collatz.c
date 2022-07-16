// Write a recursive function collatz(n) that calculates how many steps
// it takes to get to 1 of you start from n and recurse as indicated above

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Prototype:
int collatz(int n);

int main(void)
{
    int n = get_int("Integer: ");

    collatz(n);
    printf("Operation took %i steps\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    // If even:
    if (n % 2 == 0)
        // n = n / 2;
        return 1 + collatz(n / 2);
    // If odd:
    else // if (n % 2 == 1)
        // other recursive case
        // n = (3 * n) + 1;
        return 1 + collatz((3 * n) + 1);
}