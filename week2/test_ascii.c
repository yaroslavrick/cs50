#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int ascii_big_arr[] = {65, 66};
    // string word_a_b_arr[] = {'a', 'b', 'c'};
    string word = "Abc";
    if (word[0] == ascii_big_arr[0])
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }
}
