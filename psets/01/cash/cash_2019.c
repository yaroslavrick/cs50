#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int get_quarters(int cents);
int get_dimes(int cents);
int get_nickels(int cents);
int get_pennies(int cents);

int main(void)
{
    int cents = get_cents();
    // calc quarters:
    int quarters = get_quarters(cents);
    cents = cents - (quarters * 25);

    // calc dimes:
    int dimes = get_dimes(cents);
    cents = cents - (dimes * 10);

    // calc nickels:
    int nickels = get_nickels(cents);
    cents = cents - (nickels * 5);

    // calc pennies:
    int pennies = get_pennies(cents);
    cents = cents - pennies;

    // calc coins:
    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

int get_cents(void)
{
    // prompt user for an amount of change
    float amount;
    do
    {
        amount = get_float("Amount of change:");
    } while (amount < 0);
    int cents = round(amount * 100);
    return cents;
}

int get_quarters(int cents)
{
    int quarters = cents / 25;
    return quarters;
}
int get_dimes(int cents)
{
    int dimes = cents / 10;
    return dimes;
}
int get_nickels(int cents)
{
    int nickels = cents / 5;
    return nickels;
}
int get_pennies(int cents)
{
    int pennies = cents / 1;
    return pennies;
}
