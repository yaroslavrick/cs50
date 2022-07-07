# Readability CS-50's Lab made in Ruby
# Implement a program that calculates the approximate grade level needed to
# comprehend some text
require_relative 'lib/methods'

#  Prompt the user for a string of text
puts 'Text: '
text = $stdin.gets.chomp.to_s

#  Calculating number of letters in the text
letters_number = count_letters(text)
# puts "Letters: #{letters_number}"

#  Calculating number of words in the text
words_number = count_words(text)
# puts "Words: #{words_number}"

#  Calculating number of sentences in the text
sentences_number = count_sentences(text)
# puts "Sentences: #{sentences_number}"

#  Calculating grade
grade = grade_calc(letters_number, words_number, sentences_number)

#  Printing a result
result_printer(grade)
