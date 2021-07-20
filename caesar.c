#import <stdio.h>
#import <cs50.h>
#import <ctype.h>
#import <string.h>
#import <stdlib.h>

string changeText(int numKey, string text);
bool repeat(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    //Check to see if key is present in command line.
    if (argc != 2)
    {
        printf("Usage: %s key --> Enter encryption key here! <--\n", argv[0]);
        return 1;
    }
    //Iterate through characters in key and check that they are numeric.
    for (int j = 0; j < strlen(key); j++)
    {
        if (!isdigit(key[j]))
        {
            printf("Key must only contain numbers!\n");
            return 1;
        }

    }
    {   
        /*Convert key to an integer, ask user for text input, run function to convert text
        input into ciphertext and print to concole
        */
        int numKey = atoi(argv[1]);
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");
        changeText(numKey, plainText);
        printf("\n");
    }
}
//Method to change plaintText into cipherText
string changeText(int number, string plainText)
{
    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                int j = (int) plainText[i];
                int k = (((number + j) - 97) % 26) + 97;
                printf("%c", k);
            }
            else if (isupper(plainText[i]))
            {
                int l = (int) plainText[i];
                int m = (((number + l) - 65) % 26) + 65;
                printf("%c", m);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    return 0;
}