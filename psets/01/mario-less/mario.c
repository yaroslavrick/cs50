#include <cs50.h>
#include <stdio.h>

int main(void)
{
        int input;
        do
        {
                input = get_int("Height: ");
        } while (input < 1 || input > 8);
        printf("%i", input);
}