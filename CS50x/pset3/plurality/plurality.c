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
}
candidate;

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
    for (int i = 0; i < candidate_count; ++i)
    {
        for (int j = 0; name[j] != '\0'; ++j)
        {
            if (candidates[i].name[j] != name[j])
            {
                break;
            }
            else if (name[j + 1] == '\0')
            {
                ++candidates[i].votes;
                return true;
            }
        }

    }
    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int temp = 0;
    int winner = 0;
    string names[candidate_count];

    for (int i = 0; i < candidate_count; ++i)
    {
        if (candidates[i].votes > temp)
        {
            winner = 0;
            names[winner] = candidates[i].name;
            temp = candidates[i].votes;
        }
        else if (candidates[i].votes == temp)
        {
            ++winner;
            names[winner] = candidates[i].name;
        }
    }

    for (int k = 0; k <= winner; ++k)
    {
        printf("%s\n", names[k]);
    }
    // TODO
    return;
}

