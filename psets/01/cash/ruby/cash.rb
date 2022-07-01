# Cash.rb calculates how many coins customer will take

require_relative 'lib/cash_methods'

# Ask how many cents the customer is owed
cents = user_input_cents

# Calculate the number of quarters to give the customer
quarters = calculate_quarters(cents)

# Substraction number of quarters from cents
cents -= quarters * 25

# Calculate the number of dimes to give the customer
dimes = calculate_dimes(cents)

# Substraction number of dimes from cents
cents -= dimes * 10

# Calculate the number of nickels to give the customer
nickels = calculate_nickels(cents)

# Substraction number of nickels from cents
cents -= nickels * 5

# Calculate the number of pennies to give the customer
pennies = calculate_pennies(cents)

# Substraction number of pennies from cents
cents -= pennies

# Sum coins
coins = sum_of_coins(quarters, dimes, nickels, pennies)

# Print total number of coins to give the customer
puts "#{coins}\n"
