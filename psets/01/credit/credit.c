// Luhn’s Algorithm

#include <cs50.h>
#include <stdio.h>

long get_card(void);
int number_of_digits(long card);
string type_of_card(int digits, long card);
int checksum(long card);

int main(void)
{
    long card = get_card;
    int digits = number_of_digits(card);
    printf("Digits: %d\n", digits);
    string type_of_card(int digits, long card);
    int checksum(card);
}

// Methods:

// Getting card:
long get_card(void)
{
    long card;
    int digits;
    do
    {
        card = get_long("Number: ");
        digits = number_of_digits(card);
    } while (digits <= 0 && digits < 13 && digits > 16);
    return card;
}

// Counting number of digits in card
int number_of_digits(long card)
{
    int digits_count;
    for (int digits_count = 0; card > 0; card / 10)
    {
        digits_count = digits_count + 1;
    }
    return digits_count;
}

string type_of_card(int digits, long card)
{
    // reports(via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein
    // AMEX\n or MASTERCARD\n or VISA\n or INVALID\n;

    switch (card)
    {
    case 34 || 37 && (15 digits):
        printf("AMEX\n");
        break;
    case 51 || 52 || 53 || 54 || 55 && (16 digits):
        printf("MASTERCARD\n");
        break;
    case 4 && (13 digits || 16 digits):
        printf("VISA\n");
        break;
    default:
        printf("INVALID\n");
    }
}

int checksum(long card)
{
    //     Multiply every other digit by 2, starting with the number’s second - to - last digit, and then add those products’ digits together.
    // (second_to_last_digit * 2) - с предпоследнего до первого

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    // int sum_of_doubled_digits = digits1+d2+d3..

    // int summ_of_other_digits_not_doubled + sum_of_doubled_digits
    // if total's last digit is 0 - card is valid!
    // If the total’s last digit is 0(or, put more formally, if the total modulo 10 is congruent to 0), the number is valid !
}