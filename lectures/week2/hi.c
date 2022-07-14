#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);
    printf("%i %i %i\n", (char)c1, (char)c2, (char)c3);
    // Explicitly (явно) converts chars into ints
    printf("%i %i %i\n", (int)c1, (int)c2, (int)c3);

    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    string t = "BYE!";
    printf("%s\n", s);
    printf("%s\n", t);
}