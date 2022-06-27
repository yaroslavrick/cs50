# Get card number from user input:
def user_input
  card_num = 0
  puts 'Number: '
  card_num = $stdin.gets.chomp.to_i until card_num.positive?
  card_num
end

# Checking how many digits in card:
def digits_length(card_num)
  card_num.to_s.length
end

# calculate checksum (last digit is zero?)
def checksum(digits_length, card)
  sum_of_not_doubled = 0
  sum_of_doubled = 0

  while digits_length > 0
    # Достаю последнюю цифру:
    reminder = card % 10

    # Суммирую "не сдвоенные" цифры карты:
    sum_of_not_doubled += reminder

    # Убираю эту последнюю цифру с "card":
    card -= reminder

    # Убираю ноль:
    card /= 10

    #  минус одна цифра:
    digits_length -= 1

    # Достаю предпоследнню цифру:
    reminder = card % 10

    # Множу ее на два:
    doubled = reminder * 2

    # Если цифр две:
    if doubled > 9
      reminder_of_doubled = doubled % 10
      doubled -= reminder_of_doubled
      doubled /= 10
      doubled += reminder_of_doubled
    end

    # Суммирую:
    sum_of_doubled += doubled

    # Убираю остаток с карты и потом убираю ноль, чтобы добраться к следующей цифре:
    card -= reminder

    card /= 10

    digits_length -= 1

    sum = sum_of_doubled + sum_of_not_doubled
  end
  #   puts "Sum is: #{sum}"

  #   Checking if last digit == 0 or not

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
end

# Looking for first digit:
def first_digit(card, digits_length)
  card.digits[(digits_length - 1)]
end

# Looking for the second digit:
def second_digit(card, digits_length)
  card.digits[(digits_length - 2)]
end

# Printing type of card:
def print_result(digits, first_digit, second_digit)
  # AMEX:

  if (digits == 15) && (((first_digit == 3) && (second_digit == 4)) || ((first_digit == 3) && (second_digit == 7)))

    puts "AMEX\n"

  # MASTERCARD:

  elsif (digits == 16) && ((first_digit == 5 && second_digit == 1) || (first_digit == 5 && second_digit == 2) || (first_digit == 5 && second_digit == 3) || (first_digit == 5 && second_digit == 4) || (first_digit == 5 && second_digit == 5))
    puts "MASTERCARD\n"

  # VISA:

  elsif [13, 16].include?(digits) && first_digit == 4

    puts "VISA\n"

  # INVALID:

  else
    puts "INVALID\n"
    exit(0)
  end
end
