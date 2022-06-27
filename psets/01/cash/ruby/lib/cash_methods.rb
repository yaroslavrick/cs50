# Ask how many cents the customer is owed
def user_input_cents
    int number_of_cents;
    do
    {
        number_of_cents = get_int("Number of cents: ");
    } while (number_of_cents < 0);
    return number_of_cents;
    // return 63;
end


int calculate_quarters(int cents)
{

    // Implement calculate_quarters in such a way that the function calculates (and returns as an int) how many quarters a customer should be given if they’re owed some number of cents. For instance, if cents is 25, then calculate_quarters should return 1. If cents is 26 or 49 (or anything in between, then calculate_quarters should also return 1. If cents is 50 or 74 (or anything in between), then calculate_quarters should return 2. And so forth.
    int quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    // Implement calculate_dimes in such a way that the function calculates the same for dimes.
    int dimes = cents / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    // Implement calculate_nickels in such a way that the function calculates the same for nickels.
    int nickels = cents / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    // Implement calculate_pennies in such a way that the function calculates the same for pennies.
    int pennies = cents / 1;
    return pennies;
}
