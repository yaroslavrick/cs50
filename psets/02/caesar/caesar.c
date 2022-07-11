#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functions:
int check_arguments(int argc);
bool isDigit(string number);
int check_for_negative_int(string number);
string rotate_text(string plaintext, int key);

int main(int argc, string argv[])
{
    // Checking if there's more than one command-line argument
    // Checking if the command-line argument exists:
    check_arguments(argc);

    // Check if argv[1] is a digit:
    if (isDigit(argv[1]) == false)
    {
        printf("%s include non-digit value!\n", argv[1]);
        return 1;
    }

    // Check for non-negative integer in argv[1]:
    check_for_negative_int(argv[1]);

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompting user for plaintext:
    string plaintext = get_string("plaintext: ");

    // Rotate the character by key:
    string ciphertext = rotate_text(plaintext, key);

    // Output:
    // "ciphertext: "
    return 0;
}

// FUNCTIONS:

// Checking if there's more than one command-line argument
// Checking if the command-line argument exists:
int check_arguments(int argc)
// argc - argument calculating (how many words human typed in the prompt)
// argv[] - argument vector. It's going to be array of the word that human typed at the prompt
{
    // Checking if there's more than one command-line argument
    if (argc > 2)
    {
        printf("There's more than one command-line argument\n");
        return 1;
    }
    // Checking if the command-line argument exists:
    else if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // If okey:
    else
    {
        return 0;
    }
}

// Check if argv[1] is a digit:
bool isDigit(string number)
{
    // If any of the characters of the command-line argument is not a decimal digit, your program
    // should print the message Usage: ./caesar key and return from main a value of 1.

    for (int i = 0; i < strlen(number); i++)
    {
        if (isdigit(number[i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

// Check for non-negative integer in argv[1]:
// TODO
int check_for_negative_int(string number)
{
    if (number[0] == '-')
    {
        printf("Negative digit!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Rotate the character by key:
string rotate_text(string plaintext, int key)
{
    // For each character in the plaintext:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = plaintext[i] + key;
                // 65 - 90 A-Z
                if (plaintext[i] > 90)
                {
                    plaintext[i] = (((plaintext[i] + key) % 26) + 65);
                }
            }
            // printf("i = %i\n", i);
            // printf("plaintext int: %i\n", plaintext[i]);
            // plaintext[i] = plaintext[i] + key;
            // printf("plaintext int: %i\n", plaintext[i]);
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }
    // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0
    // from main.
    printf("ciphertext: %s\n", plaintext);
    return 0;
}