#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functions:
int check_arguments(int argc);
int isDigit(string number);
int check_for_negative_int(string number);

int main(int argc, string argv[])
{
    // Checking if there's more than one command-line argument
    // Checking if the command-line argument exists:
    check_arguments(argc);

    // Check if argv[1] is a digit:
    isDigit(argv[1]);

    // Check for non-negative integer in argv[1]:
    check_for_negative_int(argv[1]);

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompting user for input:
    string plaintext = get_string("plaintext: ");

    // Output:
    // "ciphertext: "

    // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
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
int isDigit(string number)
{
    // If any of the characters of the command-line argument is not a decimal digit, your program
    // should print the message Usage: ./caesar key and return from main a value of 1.

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