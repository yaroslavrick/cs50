//  implement a program that runs a plurality election
// $ ./plurality Alice Bob Charlie
// Number of voters: 4
// Vote: Alice
// Vote: Bob
// Vote: Charlie
// Vote: Alice
// Alice
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Look for a candidate called "name"
    // for ex. vote("Bob")
    // iterating candidates[i].name
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate found, update their vote total and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Print the name of candidate(s) who have the most votes
    // If tie => print each of candidates

    // Searching for the max number votes
    int max = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare elements of array with max
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    // printf("The largest element is %i\n", max);

    // Use other for-loop to check and match the votes of the candidates with int max and printf the name
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
