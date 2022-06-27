# Ask how many cents the customer is owed
def user_input_cents
  number_of_cents = 0
  puts 'Number of cents: '
  number_of_cents = $stdin.gets.chomp.to_i until number_of_cents.positive?
  number_of_cents
end

# Calculate the number of quarters to give the customer
def calculate_quarters(cents)
  cents / 25
end

# Calculate the number of dimes to give the customer
def calculate_dimes(cents)
  cents / 10
end

# Calculate the number of nickels to give the customer
def calculate_nickels(cents)
  cents / 5
end

# Calculate the number of pennies to give the customer
def calculate_pennies(cents)
  cents / 1
end

# Sum coins
def sum_of_coins(quarters, dimes, nickels, pennies)
  quarters + dimes + nickels + pennies
end
