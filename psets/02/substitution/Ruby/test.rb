# Design and implement a program, substitution, that encrypts messages using a substitution cipher.
plaintext_str = 'Hello, CS-50!'
key_str = 'VCHPRZGJNTLSKFBDQWAXEUYMOI'

# Converting string into array:
plaintext = plaintext_str.split('')
key = key_str.split('')

# Check if letter is alphabetical
def alpha?(char)
  char.match?(/^[[:alpha:]]$/)
end

# Check if letter is in uppercase
def upper?(char)
  char.match?(/^[[:upper:]]$/)
end

# # Check if letter is in lowercase
def lower?(char)
  char.match?(/^[[:lower:]]$/)
end

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

# Define variable for ciphertext:
ciphertext = ''

# iterating each plaintext's char (i-th):
plaintext.each_index do |i|
  # iterating each key's char j-th on i-th char of plaintext:
  key.each_index do |j|
    # If char in plaintext is alphabetical:
    if alpha?(plaintext[i])
      # Check if letter is in uppercase
      if upper?(plaintext[i])
        capital_letters.each_index do |k|
          # Checking if plaintext's letter is equal to alphabet's letter in [j]
          if plaintext[i].ord == capital_letters[k]
            ciphertext[i] = key[j].upcase
            break
          end
        end
      # Check if letter is in lowercase
      elsif lower?(plaintext[i])
        small_letters.each_index do |l|
          if plaintext[i].ord == small_letters[l]
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
