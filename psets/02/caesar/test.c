#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    // 1. Convert ASCII to alphabetical index
    // 2. Shift alphabetical index using formula
    // c = (p + k)%26
    // Convert result beck to ASCII

    // char c = 'Z';
    // int key = 3;
    // char cipher = ((c + key) % 26);
    // printf("%c\n", cipher);

    string plaintext = "This is CS-50";
    string cipher = "";
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Taking char:
        string cipher = cipher + (plaintext[i] + key) % 26;
        printf("%c\n", cipher);
    }
}