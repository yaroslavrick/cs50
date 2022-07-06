# Method to compute score of user's word
def compute_score(word)
  # Array of letters:
  letters = %w[a b c d e f g h
               i j k l m n o p
               r s t u v w x y z]

  # Making hash of keys of letters and values of points:
  points_hash = letters.zip(@points_arr).to_h

  # Making array from user's word:
  word_arr = word.scan(/\w/)
  # word_arr = ["b", "o", "x"]

  # counter score:
  score = 0
 puts "HEllo"
  # Iterating letters in word, looking for points
  points_hash.select do |letter, point|
    if word_arr.include?(letter)
      score += point
    end
  end
  return score
end
