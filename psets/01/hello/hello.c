#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompting name from user:
    string name = get_string("What is your name?\n");
    // Printing input:
    printf("hello, %s\n", name);
}