// Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using
// a sequence of keys (or, put another way, a keyword).
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functions:
bool check_arguments(int argc);
bool is_key_alpha(string key);
int shift(char c);
string rotate_text(string plaintext, string key);

int main(int argc, string argv[])
{
    // In other words, if p is some plaintext and k is a keyword (i.e., an alphabetical string,
    // whereby A (or a) represents 0, B (or b) represents 1, C (or c) represents 2, …, and Z (or z)
    // represents 25), then each letter, ci, in the ciphertext, c, is computed as:
    // ci = (pi + kj) % 26

    // Note this cipher’s use of kj as opposed to just k. And if k is shorter than p, then the letters in k
    // must be reused cyclically as many times as it takes to encrypt p.

    // If your program is executed without any command-line arguments or with more than one command-line argument,
    // your program should print an error message of your choice (with printf) and return from main a value of 1
    // (which tends to signify an error) immediately.
    if (check_arguments(argc) == false)
    {
        return 1;
    }

    // Declaring key string variable:
    string key = argv[1];

    // Check containing any character that is not an alphabetic character
    if (is_key_alpha(key) == false)
    {
        return 1;
    }

    // Converting key into int and shifting its chars to key of each:
    // int key = shift(key_s);
    // printf("key: %i\n", key);

    // Prompting user for plaintext:
    string plaintext = get_string("plaintext: ");

    // Rotate the character by key:
    // string ciphertext = rotate_text(plaintext, key);

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i]) - 97 + shift(key[i])) % 26 + 97);
        }
        else if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i]) - 65 + shift(key[i])) % 26 + 65);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}

// FUNCTIONS :

// Checking if there's more than one command-line argument
// Checking if the command-line argument exists:
bool check_arguments(int argc)
// argc - argument calculating (how many words human typed in the prompt)
// argv[] - argument vector. It's going to be array of the word that human typed at the prompt
{
    // Checking if there's more than one command-line argument
    if (argc > 2)
    {
        printf("Usage: ./vigenere keyword\n\n");
        return false;
    }
    // Checking if the command-line argument exists:
    else if (argc < 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return false;
    }
    // If okey:
    else
    {
        return true;
    }
}

// containing any character that is not an alphabetic character
bool is_key_alpha(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Key contains non-alphabetical chars");
            return false;
        }
    }
    return true;
}

// convert character into the correct shift value
int shift(char c)
{ // for ex. char = a == 97 ascii
    if (isalpha(c))
    {
        if (isupper(c))
        // The ASCII value of A is 65
        {
            c = c - 65;
        }
        else if (islower(c))
        // The ASCII value of a is 97
        {
            c = c - 97;
        }
    }
    else
    {
        return c;
    }
    return c;
}

// Rotate the character by key:
string rotate_text(string plaintext, string key)
{
    // For each character in the plaintext:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter
        // If alphabetical:
        if (isalpha(plaintext[i]))
        {
            // Iterating key
            for (int k = 0; k < strlen(key); k++)
            {
                // If letter is in uppercase
                if (isupper(plaintext[i]))
                {
                    // // If more than #90 ASCII (65 - 90: A - Z)
                    if ((plaintext[i] + (shift(key[k]) % 26)) > 90)
                    {
                        plaintext[i] = plaintext[i] + (shift(key[k]) % 26) - 26;
                    }
                    else
                    {
                        plaintext[i] = plaintext[i] + (shift(key[k]) % 26);
                    }
                }
                // If letter is in lowercase
                if (islower(plaintext[i]))
                {
                    // // If more than #122 ASCII (97 - 122: a - z)
                    if ((plaintext[i] + (shift(key[k]) % 26)) > 122)
                    {
                        plaintext[i] = plaintext[i] + (shift(key[k]) % 26) - 26;
                    }
                    else
                    {
                        plaintext[i] = plaintext[i] + (shift(key[k]) % 26);
                    }
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