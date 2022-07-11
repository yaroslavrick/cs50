// Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Methods:
// bool isNumber(char number);
bool isNumber(char number[]);
char rotate(char letter, int key);

// argc - argument calculating (how many words human typed in the prompt)
// argv[] - argument vector. It's going to be array of the word that human typed at the prompt
int main(int argc, char *argv[])
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

    // Check if is it a number:
    int key;
    if (isNumber(argv[1]))
    {
        // Converting string into int:
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Checking if there is no non-digits at the start of the line:
    if (key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If key is negative:
    if (key < 0)
    {
        printf("Integer is negative!\n");
        return 1;
    }

    printf("Int key is %i\n", key);

    // Prompting plain text from user:
    string plaintext = get_string("plaintext: ");

    char cipher = rotate(plaintext, key);
    printf("ciphertext: %c", cipher);
}

bool isNumber(char number[])
{
    // If any of the characters of the command-line argument is not a decimal digit,
    // your program should print the message Usage: ./caesar key and return from main a value of 1.
    int i = 0;
    // Check for empty string:
    if (strlen(number) == 0)
    {
        return false;
    }
    // Check for more than one argument && negative sign
    if (strlen(number) == 1 && number[0] == '-')
    {
        return false;
    }
    // Verifying negation sign
    if (number[0] == '-')
    {
        i = 1;
    }
    for (; number[i] != 0; i++)
    {
        // Check for non digit char:
        if (!isdigit(number))
        {
            return false;
        }
    }
    // If number:
    return true;
}

char rotate(char letter, int key)
{
    // Checks the char is alphabetical:
    if (isalpha(letter))
    {
        // If letter is in Uppercase:
        if (isupper(letter))
        {
            letter = letter + key;
        }
        // If letter is in lowercase:
        else if (islower(letter))
        {
            letter = letter + key;
        }
        return letter;
    }
    // If it's not a letter:
    else
    {
        return letter;
    }
}

// // Array for decimal digits:
// string digits_arr[] = { "1",
//                         "2",
//                         "3",
//                         "4",
//                         "5",
//                         "6",
//                         "7",
//                         "8",
//                         "9",
//                         "0" }