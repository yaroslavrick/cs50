#include <cs50.h>
#include <stdio.h>
// Lib for exit()
#include <stdlib.h>

// TODO
// - prompt to input
// - calculate checksum (last digit is zero?)
// - check the card lenght (> 13; < 17) and starting digits (Am Express, Visa, MasterCard)
// - Print AMEX; MASTERCARD; VISA; or INVALID

long get_card(void);
int number_of_digits(long card);
int checksum(long card, int digits);
int first_digit_func(long card, int digits);
int second_digit_func(long card, int digits);
int print_result(int digits, int first_digit, int second_digit);

int main(void)
{
    // - prompt to input
    long card = get_card();

    // Checking how many digits in card:
    int digits = number_of_digits(card);

    // Checking checksum:
    int sum = checksum(card, digits);

    // Looking for firts digit:
    int first_digit = first_digit_func(card, digits);

    // Lokiing for second digit:
    int second_digit = second_digit_func(card, digits);

    // Printing results:
    print_result(digits, first_digit, second_digit);
}

// Methods:

// Getting card:
long get_card(void)
{
    long card_number = get_long("Number: ");
    return card_number;
}

// Counting number of digits in card
int number_of_digits(long card)
{
    int digits_count;
    for (digits_count = 0; card > 0; card = card / 10)
    // for (initializationStatement; testExpression; updateStatement)
    {
        digits_count = digits_count + 1;
    }
    return digits_count;
}

// Checksum (Luhn’s Algorithm):
int checksum(long card, int digits)
{
    int reminder, doubled, sum_of_summs;
    int sum_of_doubled = 0;
    int sum_of_not_doubled = 0;
    int sum = 0;

    do
    {

        // Достаю последнюю цифру:
        reminder = card % 10;

        // Суммирую "не сдвоенные" цифры карты:
        sum_of_not_doubled = sum_of_not_doubled + reminder;

        // Убираю эту последнюю цифру с "card":
        card = card - reminder;

        // Убираю ноль:
        card = card / 10;

        // - одна цифра:
        digits -= 1;

        // Достаю предпоследнню цифру:
        reminder = card % 10;

        // Множу ее на два:
        doubled = reminder * 2;

        // Если цифр две:
        if (doubled > 9)
        {
            int reminder_of_doubled = doubled % 10;
            doubled = doubled - reminder_of_doubled;
            doubled = doubled / 10;
            doubled = doubled + reminder_of_doubled;
        }

        // Суммирую:
        sum_of_doubled = sum_of_doubled + doubled;

        // Убираю остаток с карты и потом убираю ноль, чтобы добраться к следующей цифре:
        card = card - reminder;

        card = card / 10;

        digits -= 1;

        sum = sum_of_doubled + sum_of_not_doubled;

    } while (digits > 0);

    // printf("Sum: %i\n", sum);

    if ((sum % 10) == 0)
    {
        return sum;
    }
    else
    {
        printf("INVALID\n");
        exit(0);
    }
}

// Getting first digit:
int first_digit_func(long card, int digits)
{
    int reminder;
    for (int i = digits; i > 1; i = i - 1)
    {
        reminder = card % 10;
        card = (card - reminder) / 10;
    }
    return card;
}

// Достаю вторую цифру карты:
int second_digit_func(long card, int digits)
{
    int reminder;
    for (int i = digits; i > 2; i = i - 1)
    {
        reminder = card % 10;
        card = (card - reminder) / 10;
    }

    int second_num = card % 10;
    return second_num;
}

// Printing results:
int print_result(int digits, int first_digit, int second_digit)
{
    // AMEX:

    if ((digits == 15) && (((first_digit == 3) && (second_digit == 4)) || ((first_digit == 3) && (second_digit == 7))))
    {
        return printf("AMEX\n");
    }
    // MASTERCARD:

    else if ((digits == 16) && ((first_digit == 5 && second_digit == 1) || (first_digit == 5 && second_digit == 2) || (first_digit == 5 && second_digit == 3) || (first_digit == 5 && second_digit == 4) || (first_digit == 5 && second_digit == 5)))
    {
        return printf("MASTERCARD\n");
    }

    // VISA:

    else if ((digits == 13 || digits == 16) && first_digit == 4)
    {
        return printf("VISA\n");
    }

    // INVALID:

    else
    {
        printf("INVALID\n");
        exit(0);
    }
}
