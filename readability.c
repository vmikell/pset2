#import <stdio.h>
#import <cs50.h>
#import <string.h>
#import <ctype.h>
#import <math.h>

float countLetters(string text);
float countWords(string text);
float countSentences(string text);

/*
This program promts a user to inout text, and the approximate grade level
needed to comprehend text is determined
*/

int main(void)
{
    
    /*
    User is prompted to enter text to be evaluated and the number of letters,
    words and sentences that appear in the string are stored as float
    */
    string text = get_string("Text: ");
    float numOfLetters = countLetters(text);
    float numOfWords = countWords(text);
    float numOfSentences = countSentences(text);
    /*
    The average, given 100 is found for letters/words and sentences/words. These 
    values are then plugged into the Coleman-Liau Index to determine the grade 
    level necesarry to evaluate the text
    */
    float L = (numOfLetters / numOfWords) * 100;
    float S = (numOfSentences / numOfWords) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    /*
    float index is changed to an int and rounded to the next whole number. The 
    logic that proceeds prints values for grades below 1, 1 to 15 and above 16, inclusive 
    */

    if ((int) round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

/*
countLetters determines the quantity of letters in a string,
not taking into account non-alphanumeric chars
*/

float countLetters(string text)
{
    float count = 0;
    for (int i = 0; i < strlen(text); i++)
        if (isalpha(text[i]))
        {
            count++;
        }
    return count;
}

/*
countWords determines the number of wors in a string by counting
the spaces between words starting from 1 and assuming no space 
char are used at the begining or end of the string
*/

float countWords(string text)
{
    float count = 1;
    for (int i = 0; i < strlen(text); i++)
        if (isspace(text[i]))
        {
            count++;
        }
    return count;
}

/*
countSentences detemines the number of sentences in a string, assuming 
all sentences end with '!','.', or '?', and counting the number of times these 
char appear
*/

float countSentences(string text)
{
    float count = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count++;
        }
    return count;
}
