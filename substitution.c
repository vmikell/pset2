#import <stdio.h>
#import <cs50.h>
#import <ctype.h>
#import <string.h>
#import <stdlib.h>

string changeText(string keyText, string text);
bool repeat(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: %s key --> Enter encryption key here! <--\n", argv[0]);
        return 1;
    }
    
    
        
    if (strlen(key) != 26)
    {
        printf("Key must contian 26 characters!\n");
        return 1;
    }
    
    for(int j = 0; j < strlen(key); j++)
    {
        if (!isalpha(key[j]))
        {
            printf("Key must only contain letters!\n");
            return 1;
        }
        
    }
    {
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");
        changeText(key, plainText);
        printf("\n");
    }
}

string changeText(string keyText, string plainText)
{
    string changeText;
    int i;
    int total = 0;
    for (i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
			if (islower(plainText[i]))
		    {
			    printf("%c", tolower(keyText[plainText[i] - 'a']));
		    }
		    else if (isupper(plainText[i]))
		    {
			    printf("%c", toupper(keyText[plainText[i] - 'A']));
		    }
	    }
	    else
	    {
		    printf("%c", plainText[i]);
	    }
    }

	return 0;
}

bool repeat(string str)
{
    if (islower(str))
    {
    int repeat[26] = {0};
    for (int i = 0; i < 26; i++)
    {
	    if (repeat[toupper(str[i] - 'A')] > 0)
	    {
	         printf("No duplicate characters allowed!\n");
	         return false;
	         repeat[toupper(str[i] - 'A')]++;
	    }
    }   
    return true; 
    }
    return true;
}