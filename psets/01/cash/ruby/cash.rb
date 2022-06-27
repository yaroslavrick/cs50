require_relative 'lib/cash_methods'

# Ask how many cents the customer is owed
cents = user_input_cents

# Calculate the number of quarters to give the customer
quarters = calculate_quarters(cents)
cents -= quarters * 25

# Calculate the number of dimes to give the customer
dimes = calculate_dimes(cents)
cents -= dimes * 10

# Calculate the number of nickels to give the customer
nickels = calculate_nickels(cents)
cents -= nickels * 5

# Calculate the number of pennies to give the customer
pennies = calculate_pennies(cents)
cents -= pennies

# Sum coins
coins = sum_of_coins(quarters, dimes, nickels, pennies)

# Print total number of coins to give the customer
puts "#{coins}\n"
