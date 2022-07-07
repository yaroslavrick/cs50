# Methods for readability.rb

#  Calculating number of letters in the text
def count_letters(text)
  text.count('a-zA-Z')
end

# Calculating number of words in the text
def count_words(text)
  words_counter = text.count ' '
  words_counter += 1
  words_counter
end

# Calculating number of sentences in the text
def count_sentences(text)
  text.count('.!?')
end

# Calculating grade
def grade_calc(letters, words, sentences)
  # The formula is

  # index = 0.0588 * L - 0.296 * S - 15.8

  # where L is the average number of letters per 100 words in the text,
  # and S is the average number of sentences per 100 words in the text.
  # index = (0.0588 * ((letters_number / words_number) * 100)) - (0.296 * ((sentences_number / words_number) * 100)) - 15.8
  l = (letters.to_f / words.to_f) * 100
  s = (sentences.to_f / words.to_f) * 100
  index = (0.0588 * l) - (0.296 * s) - 15.8
  #   puts "Index: #{index}"
  # Rounding float to int
  index.round
  #   puts "Rounded index: #{grade}"
end

# Printing a result
def result_printer(grade)
  if grade < 1
    puts 'Before Grade 1'
  elsif grade >= 1 && grade < 16
    puts "Grade #{grade}"
  elsif grade >= 16
    puts 'Grade 16+'
  else
    puts 'Error!'
  end
end
