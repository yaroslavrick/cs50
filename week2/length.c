#include <stdio.h>
#include <cs50.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("Length is %i\n", length);
}

int string_length(string s)
{
    int i = 0;
    // '\0' - special nul character
    while (s[i] != '\0')
    {
        i++;
    }

    return i;

    // // Var2:
    // int length = 0;
    // for (int j = 0; name[j] != '\0'; j++)
    // {
    //     length++;
    // }
    // return j;
}