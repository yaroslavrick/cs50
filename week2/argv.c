#include <cs50.h>
#include <stdio.h>

// argc - argument calculating (how many wordshuman typed in the prompt)
// argv[] - argument vector. It's going to be arrayof the word that human typed at the prompt
int main(int argc, string argv[])
{
    // If arguments in command line is 2:
    // the first - name of program
    // the second - is command prompt
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}