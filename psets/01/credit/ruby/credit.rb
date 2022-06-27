# // TODO
# // - prompt to input
# // - calculate checksum (last digit is zero?)
# // - check the card lenght (> 13; < 17) and starting digits (Am Express, Visa, MasterCard)
# // - Print AMEX; MASTERCARD; VISA; or INVALID

# Valid VISA:
# 4003600000000014

require_relative 'credit_methods'

# Get card number from user input:
card = user_input

# Checking how many digits in card:
digits_length = digits_length(card)

# calculate checksum (last digit is zero?)
checksum(digits_length, card)

# Looking for firts digit:
first_digit = first_digit(card, digits_length)

# Looking for the second digit:
second_digit = second_digit(card, digits_length)

# Printing type of card:
print_result(digits_length, first_digit, second_digit)
