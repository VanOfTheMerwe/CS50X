#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declare the points for the letters.
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes:
int get_score(string word);

int main(void)
{
    // Get words from two players:
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate who the winner is:
    int score1 = get_score(word1);
    int score2 = get_score(word2);

    // Print winner:
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }
    else
        printf("Tie!\n");
}

// Function definition (the prototype):
int get_score(string word)
{
    // initialize score to keep track of earned points:
    int score = 0;

// Calculate the score for each character individually:
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
