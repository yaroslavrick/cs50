#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // If the user doesn’t, in fact, input a positive integer between 1 and 8,
    // inclusive, when prompted, the program should re-prompt the user until ///// they cooperate:
    int height;
    do
    {
        height = get_int("Height:");
    } while (height < 1 || height > 8);
    for (int i = 0; i <= height; i++)
    {
        // Printing space before hash:
        for (int j = 0; j < (height - i); j++)
        {
            printf(" ");
        }
        // Printing left hashes before gap:
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Printing gap:
        printf("  ");
        // Printing right hashes after gap:
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        // Newline
        printf("\n");
    }
}
