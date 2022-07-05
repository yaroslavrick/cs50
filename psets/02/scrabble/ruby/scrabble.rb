# CS50 Lab 2 Scrabble
require_relative 'lib/compute_score'

# Points assigned to each letter of the alphabet

@points_arr = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10]

# Get input words from both players
puts 'Player 1: '
word1 = $stdin.gets.downcase.chomp
puts 'Player 2: '
word2 = $stdin.gets.downcase.chomp

#  Compute and return score for string

compute_score(word1)
compute_score(word2)

# Print the winner
if compute_score(word1) > compute_score(word2)
  puts "Player 1 wins"
elsif compute_score(word2) > compute_score(word1)
  puts "Player 2 wins"
else
  puts "Tie!"
end
