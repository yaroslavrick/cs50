// Design and implement a program, substitution, that encrypts messages using a substitution cipher.
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functions:
bool check_arguments(int argc);
bool is_key_26_char(string key);
bool is_key_alpha(string key);
bool is_chars_not_repeated(string key);
string encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Your program must accept a single command-line argument, the key to use for the substitution.

    // The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase
    // should not affect the behavior of your program.

    // If your program is executed without any command-line arguments or with more than one command-line argument,
    // your program should print an error message of your choice (with printf) and return from main a value of 1
    // (which tends to signify an error) immediately.
    if (check_arguments(argc) == false)
    {
        return 1;
    }

    // If the key is invalid (as by not containing 26 characters, containing any character that is not
    // an alphabetic character, or not containing each letter exactly once), your program should print an
    // error message of your choice (with printf) and return from main a value of 1 immediately.
    string key = argv[1];
    if (is_key_26_char(key) == false)
    {
        return 1;
    }

    // Check containing any character that is not an alphabetic character
    if (is_key_alpha(key) == false)
    {
        return 1;
    }
    // Check for repeated characters (case insensitive)
    if (is_chars_not_repeated(key) == false)
    {
        return 1;
    }

    // Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext
    // (using get_string).
    string plaintext = get_string("plaintext: ");

    // Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding
    // ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character
    // in the ciphertext; non-alphabetical characters should be outputted unchanged.
    string ciphertext = encipher(plaintext, key);

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
        printf("Usage: ./substitution key\n");
        return false;
    }
    // If okey:
    else
    {
        return true;
    }
}

// If the key is invalid (as by not containing 26 characters, containing any character that is not
// an alphabetic character, or not containing each letter exactly once), your program should print an
// error message of your choice (with printf) and return from main a value of 1 immediately.

// Check containing 26 characters in key
bool is_key_26_char(string key)
{
    // not containing 26 characters
    if (strlen(key) < 26)
    {
        printf("Key length is less than 26 (%li)\n", strlen(key));
        return false;
    }
    else if (strlen(key) > 26)
    {
        printf("Key length is more than 26 (%li)\n", strlen(key));
        return false;
    }
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

// Check for repeated characters (case insensitive)
bool is_chars_not_repeated(string key)
{
    // loop which increases value of i after checking 26 times of k
    for (int i = 0; i < strlen(key); i++)
    {
        for (int k = 0; k < strlen(key); k++)
        {
            // when i is equal to k it does not check the condition since that step must be skipped
            if (i != k)
            {
                // checking if same character is repeated
                if (key[i] == key[k])
                {
                    printf("Key must not contain repeated characters\n");
                    return false;
                }
            }
        }
    }
    return true;
}

// Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding
// ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character
// in the ciphertext; non-alphabetical characters should be outputted unchanged.
string encipher(string plaintext, string key)
{
    // TODO:
    // 1. For each alphabetic character, determine what letters it maps to
    // 2. Preserve case
    // 3. Leave non-alphabetic characters as-is

    // Your program must preserve case: capitalized letters must remain capitalized letters;
    // lowercase letters must remain lowercase letters.

    // ASCII arrays value assigned to capital letters for alphabets
    int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

    // ASCII arrays value assigned to small letters for alphabets
    int small_letters[] = {97,
                           98,
                           99,
                           100,
                           101,
                           102,
                           103,
                           104,
                           105,
                           106,
                           107,
                           108,
                           109,
                           110,
                           111,
                           112,
                           113,
                           114,
                           115,
                           116,
                           117,
                           118,
                           119,
                           120,
                           121,
                           122};
    string ciphertext = plaintext;
    // iterating each plaintext's char (i-th):
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // iterating each key's char j-th on i-th char of plaintext:
        for (int j = 0; j < strlen(key); j++)
        {
            // If char in plaintext is alphabetical:
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    // Checking if plaintext's letter is equal to alphabet's letter in [j]
                    if (plaintext[i] == capital_letters[j])
                    {

                        ciphertext[i] = toupper(key[j]);
                        break;
                    }
                }
                else if (islower(plaintext[i]))
                {
                    if (plaintext[i] == small_letters[j])
                    {
                        ciphertext[i] = tolower(key[j]);
                        break;
                    }
                }
            }
            // if non-alphabetical:
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
    }
    // plaintext;
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}