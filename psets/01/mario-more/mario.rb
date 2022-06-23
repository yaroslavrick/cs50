puts "What's the height of pyramid you want?"

height = 0
height = $stdin.gets.chomp.to_i while height.negative? || height.zero? || height > 8

height.times do |i|
  i += 1
  # Printing space before hash:
  print(' ' * (height - i))

  # Printing left hashes before gap:
  print('#' * (height - (height - i)))

  # Printing gap:
  print('  ')

  # Printing right hashes after gap:
  print('#' * (height - (height - i)))

  # Printing newline:
  puts
end
