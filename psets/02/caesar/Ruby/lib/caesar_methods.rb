# Caesar methods:

# Check if argv is a digit:
def digit?(argv)
  # 48 is ASCII code of 0
  # 57 is ASCII code of 9
  argv.each do |argument|
    argument.each_char do |char|
      ascii = char.ord
      # Check for non-negative integer in argv[1]:
      if ascii == 45
        puts 'Negative digit!'
        return false
      end
      # Check for non-digit value
      if ascii < 48 || ascii > 57
        puts "Error: \"#{char}\" is non-digit char!"
        return false
      end
    end
  end
end

# Rotate the character by key:
def rotate_text(plaintext, key)
  # For each character in the plaintext:
  ciphertext = ''
  plaintext.each_char do |char|
    # Rotate the character if it's a letter
    ascii = char.ord
    # If letter is in uppercase. ASCII (65 - 90: A - Z)
    ciphertext << if ascii >= 65 && ascii <= 90
                    # If more than #90
                    if (ascii + (key % 26)) > 90
                      (ascii + (key % 26) - 26)
                    else
                      (ascii + (key % 26))
                    end
                  # If letter is in lowercase. ASCII (97 - 122: a - z)
                  elsif ascii >= 97 && ascii <= 122
                    # If more than #122 ASCII
                    if (ascii + (key % 26)) > 122
                      (ascii + (key % 26) - 26)
                    else
                      (ascii + (key % 26))
                    end
                  # If non-alphabetical:
                  else
                    ascii
                  end
  end
  puts "ciphertext: #{ciphertext}"
end
