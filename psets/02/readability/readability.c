#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Design:
// Your program must prompt the user for a string of text using get_string.
// Your program should count the number of letters, words, and sentences in the text.
// You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z,
// any sequence of characters separated by spaces should count as a word, and that any occurrence of a period,
// exclamation point, or question mark indicates the end of a sentence.
// Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula,
// rounded to the nearest integer.
// If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading
// level), your program should output "Grade 16+" instead of giving the exact index number.
// If the index number is less than 1, your program should output "Before Grade 1".

// Function’s prototypes:
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_calc(float letters_number, float words_number, float sentences_number);
int result_printer(int grade);

int main(void)
{
    // Prompt the user for a string of text
    string text = get_string("Text: \n");

    // Calculating number of letters in the text
    int letters_number = count_letters(text);

    // Calculating number of words in the text
    int words_number = count_words(text);

    // Calculating number of sentences in the text
    int sentences_number = count_sentences(text);

    // Calculating grade
    int grade = grade_calc(letters_number, words_number, sentences_number);

    // Printing a result
    result_printer(grade);

}

// Calculating number of letters in the text
int count_letters(string text)
{
    // Declaring counter of letters in text
    int letters_counter = 0;

    // Checks if the letter is alphabetical
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters_counter += 1;
        }
    }
    return letters_counter;
}

// Calculating number of words in the text
int count_words(string text)
{
    int words_counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words_counter += 1;
        }
    }
    return words_counter;
}

// Calculating number of sentences in the text
int count_sentences(string text)
{
    int sentences_counter = 0;

    for (int i = 0; i < strlen(text); i++)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences_counter += 1;
        }

    return sentences_counter;
}

// Calculating grade
int grade_calc(float letters_number, float words_number, float sentences_number)
{
    // The formula is

// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text,
// and S is the average number of sentences per 100 words in the text.
    // float index = (0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8;

    float letters_per_words = (letters_number / words_number) * 100;
    float sentences_per_words = (sentences_number / words_number) * 100;
    float index = 0.0588 * letters_per_words - 0.296 * sentences_per_words - 15.8;

    int grade = round(index);
    return grade;
} 
  
// Printing a result
int result_printer(int grade)
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Error!\n");
    }
    return 0;
}