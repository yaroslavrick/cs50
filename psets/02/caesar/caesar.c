#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functions:
bool check_arguments(int argc);
bool isDigit(string number);
bool isNegative_int(string number);
string rotate_text(string plaintext, int key);

int main(int argc, string argv[])
{
    // Checking if there's more than one command-line argument
    // Checking if the command-line argument exists:
    if (check_arguments(argc) == false)
    {
        return 1;
    }

    // Check if argv[1] is a digit:
    if (isDigit(argv[1]) == false)
    {
        printf("%s include non-digit value!\n", argv[1]);
        return 1;
    }

    // Check for non-negative integer in argv[1]:
    if (isNegative_int(argv[1]))
    {
        return 1;
    }

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
bool check_arguments(int argc)
// argc - argument calculating (how many words human typed in the prompt)
// argv[] - argument vector. It's going to be array of the word that human typed at the prompt
{
    // Checking if there's more than one command-line argument
    if (argc > 2)
    {
        printf("There's more than one command-line argument\n");
        return false;
    }
    // Checking if the command-line argument exists:
    else if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    // If okey:
    else
    {
        return true;
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
bool isNegative_int(string number)
{
    if (number[0] == '-')
    {
        printf("Negative digit!\n");
        return false;
    }
    else
    {
        return true;
    }
}

// Rotate the character by key:
string rotate_text(string plaintext, int key)
{
    // For each character in the plaintext:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter

        // If alphabetical:
        if (isalpha(plaintext[i]))
        {
            // If letter is in uppercase
            if (isupper(plaintext[i]))
            {
                // // If more than #90 ASCII (65 - 90: A - Z)
                if ((plaintext[i] + (key % 26)) > 90)
                {
                    plaintext[i] = plaintext[i] + (key % 26) - 26;
                }
                else
                {
                    plaintext[i] = plaintext[i] + (key % 26);
                }
            }
            // If letter is in lowercase
            if (islower(plaintext[i]))
            {
                // // If more than #122 ASCII (97 - 122: a - z)
                if ((plaintext[i] + (key % 26)) > 122)
                {
                    plaintext[i] = plaintext[i] + (key % 26) - 26;
                }
                else
                {
                    plaintext[i] = plaintext[i] + (key % 26);
                }
            }
        }
        // If non-alphabetical:
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