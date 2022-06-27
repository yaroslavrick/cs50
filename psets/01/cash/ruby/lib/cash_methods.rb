# Ask how many cents the customer is owed
def user_input_cents
  number_of_cents = 0
  puts 'Number of cents: '
  number_of_cents = $stdin.gets.chomp.to_i until number_of_cents.positive?
  number_of_cents
end

def calculate_quarters(cents)
  cents / 25
end

def calculate_dimes(cents)
  cents / 10
end

def calculate_nickels(cents)
  cents / 5
end

def calculate_pennies(cents)
  cents / 1
end
