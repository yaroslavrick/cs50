# Implement a program that encrypts messages using Caesar’s cipher
require_relative "lib/caesar_methods"

# Variable for command-line arguments:
command_line_args = ARGV
# Checking if the command-line argument exists:
if command_line_args.empty?
  puts "Usage: caesar.rb key"
  exit
end
# Checking if there's more than one command-line argument:
if command_line_args.size > 2
  puts "Usage: caesar.rb key"
  exit
end

# Check if ARGV[0] is a digit and checking for positive integer:
if digit?(command_line_args) == false
  puts "Usage: caesar.rb key"
  exit
end

# Convert argv[1] from an `array` to an `int`
key = command_line_args[0].to_i
# Testing break
puts key

# Prompting user for plaintext:
puts "plaintext: "
plaintext = $stdin.gets.chomp

# Rotate the character by key:
rotate_text(plaintext, key)
