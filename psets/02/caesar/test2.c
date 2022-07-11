#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number: ");
    int len = strlen(number);
    printf("Strlen: %i\n", len);
    if (number[0] == '-')
    {
        printf("Negative digit!\n");
        return 1;
    }
    // Check if argv[1] is a digit:
    for (int i = 0; i < strlen(number); i++)
    {
        if (isdigit(number[i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}