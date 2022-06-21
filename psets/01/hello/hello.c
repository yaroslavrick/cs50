#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompting name from user:
    string name = get_string("What is your name?\n");
    // printing input:
    printf("hello, %s\n", name);
}