# Methods for substruction app

# Checking if there's more than one command-line argument
# Checking if the command-line argument exists:
def arguments_valid?(command_line_args)
  # Checking if there's more than one command-line argument
  if command_line_args.size > 1
    puts("There's more than one command-line argument")
    false
  # Checking if the command-line argument exists:
  elsif command_line_args.empty?
    puts('Usage: ./substitution key')
    false
  # If okey:
  else
    true
  end
end

# If the key is invalid (as by not containing 26 characters, containing any character that is not
# an alphabetic character, or not containing each letter exactly once), your program should print an
# error message of your choice (with printf) and return from main a value of 1 immediately.

# Check containing 26 characters in key
def key_26_char?(key)
  # not containing 26 characters
  if key.size < 26
    puts "Key length is less than 26 #{key.size}"
    false
  elsif key.size > 26
    puts "Key length is more than 26 #{key.size}"
    false
  else
    true
  end
end

# Check if letter is alphabetical
def alpha?(char)
  char.match?(/^[[:alpha:]]$/)
end

def upper?(char)
  char.match?(/^[[:upper:]]$/)
end

def lower?(char)
  char.match?(/^[[:lower:]]$/)
end

# Containing any character that is not an alphabetic character
def key_alpha?(key)
  key.each_char do |char|
    if alpha?(key[char]) == false
      puts 'Key contains non-alphabetical chars'
      return false
    end
  end
  true
end

# Check for repeated characters (case insensitive)
def chars_not_repeated?(key)
  key_arr = key.downcase.chars
  # Counting number of unique letters
  if key_arr.uniq.count == key.size
    true
  else
    puts 'Key must not contain repeated characters'
    false
  end
end

# Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding
# ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character
# in the ciphertext; non-alphabetical characters should be outputted unchanged.
def encipher(plaintext, key)
  # TODO:
  # 1. For each alphabetic character, determine what letters it maps to
  # 2. Preserve case
  # 3. Leave non-alphabetic characters as-is

  # Your program must preserve case: capitalized letters must remain capitalized letters;
  # lowercase letters must remain lowercase letters.

  # ASCII arrays value assigned to capital letters for alphabets
  capital_letters = [65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
                     88, 89, 90]
  # ASCII arrays value assigned to small letters for alphabets
  small_letters = [97,
                   98,
                   99,
                   100,
                   101,
                   102,
                   103,
                   104,
                   105,
                   106,
                   107,
                   108,
                   109,
                   110,
                   111,
                   112,
                   113,
                   114,
                   115,
                   116,
                   117,
                   118,
                   119,
                   120,
                   121,
                   122]
  ciphertext = plaintext
  # iterating each plaintext's char (i-th):
  # for (int i = 0; i < strlen(plaintext); i++)
  plaintext.each_char do |i|
    # iterating each key's char j-th on i-th char of plaintext:
    # for (int j = 0; j < strlen(key); j++)
    key.each_char do |j|
      # If char in plaintext is alphabetical:
      if alpha?(plaintext[i])
        if upper?(plaintext[i])
          capital_letters.each do |k|
            # Checking if plaintext's letter is equal to alphabet's letter in [j]
            if plaintext[i].ord == capital_letters[j]
              ciphertext[i] = key[j].upcase
              break
            end
          end
        elsif lower?(plaintext[i])
          small_letters.each do |l|
            if plaintext[i].ord == small_letters[j]
              ciphertext[i] = key[j].downcase
              break
            end
          end
        end
      # if non-alphabetical:
      else
        ciphertext[i] = plaintext[i]
      end
    end
  end
  puts "ciphertext: #{ciphertext}"
  ciphertext
end
