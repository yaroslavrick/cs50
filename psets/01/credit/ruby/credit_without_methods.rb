# Get card number from user input:
card = 0
puts 'Number: '
card = $stdin.gets.chomp.to_i until card.positive?

# Checking how many digits in card:

digits_length = card.to_s.length

# Сalculate checksum (last digit is zero?)

sum_of_not_doubled = 0
sum_of_doubled = 0
card_to_calc = card
digits_length_to_calc = digits_length

while digits_length_to_calc.positive?
  # Достаю последнюю цифру:
  reminder = card_to_calc % 10

  # Суммирую "не сдвоенные" цифры карты:
  sum_of_not_doubled += reminder

  # Убираю эту последнюю цифру с "card":
  card_to_calc -= reminder

  # Убираю ноль:
  card_to_calc /= 10

  #  минус одна цифра:
  digits_length_to_calc -= 1

  # Достаю предпоследнню цифру:
  reminder = card_to_calc % 10

  # Множу ее на два:
  doubled = reminder * 2

  # Если цифр две:
  if doubled > 9
    reminder_of_doubled = doubled % 10
    doubled -= reminder_of_doubled
    doubled /= 10
    doubled += reminder_of_doubled
  end

  # Суммирую удвоенные:
  sum_of_doubled += doubled

  # Убираю остаток с карты и потом убираю ноль, чтобы добраться к следующей цифре:
  card_to_calc -= reminder
  card_to_calc /= 10
  digits_length_to_calc -= 1

  # Суммирую все цифры:
  sum = sum_of_doubled + sum_of_not_doubled

end

#   Checking if last digit is 0 then card is VALID

if (sum % 10) == 0
  sum
else
  puts "INVALID\n"
  exit(0)
end

# or:

# if sum.digits.first.zero?
#   puts 'Valid!'
# else
#   puts 'INVALID!'
#   exit
# end

# Looking for first digit:
first_digit = card.digits[digits_length - 1]

# Looking for the second digit:
second_digit = card.digits[(digits_length - 2)]

# Printing type of card:

# AMEX:

if (digits_length == 15) && (((first_digit == 3) && (second_digit == 4)) || ((first_digit == 3) && (second_digit == 7)))

  puts "AMEX\n"

# MASTERCARD:

elsif (digits_length == 16) && ((first_digit == 5 && second_digit == 1) || (first_digit == 5 && second_digit == 2) || (first_digit == 5 && second_digit == 3) || (first_digit == 5 && second_digit == 4) || (first_digit == 5 && second_digit == 5))
  puts "MASTERCARD\n"

# VISA:

elsif [13, 16].include?(digits_length) && first_digit == 4

  puts "VISA\n"

# INVALID:

else
  puts "INVALID\n"
  exit(0)
end
