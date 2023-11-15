#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    for ( int i = 0; word[i] != '\0'; i++)
    {
        if(isalpha(word[i]))
        {
            if(word[i] >= 65 && word[i] <= 90)
            {
                int position = 'A' - word[i];
                int index = abs(position);
                score += POINTS[index];
            }else if(word[i] >= 97 && word[i] <= 122)
            {
                int place = 'a' - word[i];
                int n = abs(place);
                score += POINTS[n];
            }

        }
    }
    return score;
}

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);



    // TODO: Print the winner
     if (score1 > score2)
     {
        printf("player 1 wins with a score of %d\n", score1);
     }else if (score2 > score1)
     {
        printf("player 2 wins with a score of %d \n", score2);
     }else if (score1 == score2)
     {
        printf("tie\n");
     }



    return 0;
}
