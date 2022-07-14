#include <cs50.h>

// Returns the sum of two ints read from stdin, or INT_MAX if there was an error.
int add_ints(void)
{
    // read int from stdin
    int i = get_int("Enter an int: ");

    // make sure we read one successfully
    if (i == INT_MAX)
    {
        return INT_MAX;
    }

    int j = get_int("What do you want to add %d to? ", i);

    if (j == INT_MAX)
    {
        return INT_MAX;
    }

    return i + j;
}