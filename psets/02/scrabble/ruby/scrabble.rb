# Methods
def compute_score(word)
  # todo
  letters = %w[a b c d e f g h
               i j k l m n o p
               r s t u v w x y z]

  word_arr = word.scan(/\w/)

  # word_arr = ["b", "o", "x"]
  word_arr.each_with_index do |letter, index|
    # letter = "b"
    # index = "0"
    puts letters[letter]
    
    # score += @points_arr[index] if word_arr[letter] == letters[letter]
  end
  # puts score
end

# Points assigned to each letter of the alphabet

@points_arr = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10]
score = 0

# Get input words from both players
puts 'Player 1: '
word1 = $stdin.gets.chomp
puts 'Player 2: '
word2 = $stdin.gets.chomp

# TODO: Print the winner
# "Player 1 wins!\n"
# "Player 1 wins!\n"
# "Tie!\n"

compute_score(word1)
compute_score(word2)
#  TODO: Compute and return score for string
