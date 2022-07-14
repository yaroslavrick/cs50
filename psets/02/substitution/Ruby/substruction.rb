# Design and implement a program, substitution, that encrypts messages using a substitution cipher.
require_relative 'lib/methods'

# Your program must accept a single command-line argument, the key to use for the substitution.

# The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase
# should not affect the behavior of your program.

# If your program is executed without any command-line arguments or with more than one command-line argument,
# your program should print an error message of your choice (with printf) and return from main a value of 1
# (which tends to signify an error) immediately.
# key example:
# VcHpRzGjNtLsKfBdQwAxEuYmOi
# Variable for command-line arguments:
command_line_args = ARGV

exit if arguments_valid?(command_line_args) == false

# Converting command_line_args to string
key = command_line_args.join('')

# If the key is invalid (as by not containing 26 characters, containing any character that is not
# an alphabetic character, or not containing each letter exactly once), your program should print an
# error message of your choice (with printf) and return from main a value of 1 immediately.
exit if key_26_char?(key) == false

# Check containing any character that is not an alphabetic character
exit if key_alpha?(key) == false

# Check for repeated characters (case insensitive)
exit if chars_not_repeated?(key) == false

# Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext
puts 'plaintext: '
plaintext = $stdin.gets.chomp

# Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding
# ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character
# in the ciphertext; non-alphabetical characters should be outputted unchanged.
encipher(plaintext, key)
