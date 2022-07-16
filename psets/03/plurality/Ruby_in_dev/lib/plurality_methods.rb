# Update vote totals given a new vote
def vote?(name)
end
# {
#     // Look for a candidate called "name"
#     // for ex. vote("Bob")
#     // iterating candidates[i].name
#     for (int i = 0; i < candidate_count; i++)
#     {
#         // If candidate found, update their vote total and return true
#         if (strcmp(candidates[i].name, name) == 0)
#         {
#             candidates[i].votes++;
#             return true;
#         }
#     }
#     return false;
# }

# // Print the winner (or winners) of the election
# void print_winner(void)
# {
#     // TODO
#     // Print the name of candidate(s) who have the most votes
#     // If tie => print each of candidates

#     // Searching for the max number votes
#     int max = candidates[0].votes;
#     for (int i = 0; i < candidate_count; i++)
#     {
#         // Compare elements of array with max
#         if (candidates[i].votes > max)
#         {
#             max = candidates[i].votes;
#         }
#     }
#     // printf("The largest element is %i\n", max);

#     // Use other for-loop to check and match the votes of the candidates with int max and printf the name
#     for (int i = 0; i < candidate_count; i++)
#     {
#         if (candidates[i].votes == max)
#         {
#             printf("%s\n", candidates[i].name);
#         }
#     }

#     return;
# }
