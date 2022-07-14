#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        // Because 1 is not 0. It saids that something gone wrong
        printf("There is not arguments in the line!\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    // int main returns 0 by the default
    return 0;
}