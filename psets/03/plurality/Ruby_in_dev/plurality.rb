# implement a program that runs a plurality election
# $ ruby plurality.rb Alice Bob Charlie
# Number of voters: 4
# Vote: Alice
# Vote: Bob
# Vote: Charlie
# Vote: Alice
# Alice
require_relative 'lib/plurality_methods'

# Max number of candidates
MAX = 9

# Candidates have name and vote count
# candidates = {}

# Variable for command-line arguments:
command_line_args = ARGV

# Check for invalid usage
if command_line_args.empty?
  puts 'Usage: plurality.rb [candidate ...]'
  exit
end

# Populate array of candidates
candidate_count = command_line_args.size
if candidate_count > MAX
  puts "Maximum number of candidates is #{MAX}"
  exit
end

# Adding candidate names to hash
candidates_arr = command_line_args

puts 'Number of voters: '
voter_count = $stdin.gets.chomp.to_i

# Loop over all voters
voter_count.times do |_voter|
  puts 'Vote: '
  name = $stdin.gets.chomp.to_s
  # Check for invalid vote
  puts 'Invalid vote.' if vote?(name) == false
end

# Display winner of election
print_winner
