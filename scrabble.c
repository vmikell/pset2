#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);


int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    //Prints winner to the console
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("player 2 wins!\n");
    }


}
 
/*
compute_score determines if a character in a string is lowercase, and converts
to uppercase. It then determines the ASCII value of the character and subtracts 
65 (ASCII value of 'A') to find the corresponding index value in POINTS[]. 
The integer at that index value is added to itself every time the loop is 
performed to calculate the total score for the word.
*/
    
int compute_score(string word)
{
    int total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
        }
        else
        {
        
        }
        int pointValue = POINTS[((int) word[i]) - 65];
        total = pointValue + total;
    }
    return total;
}
