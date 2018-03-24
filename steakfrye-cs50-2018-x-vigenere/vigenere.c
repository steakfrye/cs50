#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //makes sure user is inputting a correct argument
    if (argc != 2)
    {
        printf("Please input a single keyword.\n");

        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Please use alphabetical characters only.\n");

                return 1;
            }
        }
    }
    //declare variables
    string key = argv[1];
    int keyl = strlen(key);

    //ask user for text to be enciphered
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    //begin enciphering text by walking through each character of text
    for (int j = 0, k = 0, n = strlen(text); j < n; j++)
    {
        //declare variables
        char ltr = text[j];
        int ltrkey = tolower(key[k % keyl]) - 'a';

        //if the text has a character that is not alphabetical, no change needed
        if (!isalpha(ltr))
        {
            printf("%c", ltr);
        }

        else if (isupper(ltr))
        {
            //the enciphered letter is the original, minus its ASCII value, plus the key letter,
            //and then placed back into it's ASCII value
            ltr = (ltr - 'A' + ltrkey) % 26 + 'A';
            printf("%c", ltr);
            k++;
        }
        else if (islower(ltr))
        {
            //same as above but lowercase
            ltr = (ltr - 'a' + ltrkey) % 26 + 'a';
            printf("%c", ltr);
            k++;
        }
        else
        {
            printf("Whoops");
        }
    }
    printf("\n");

    return 0;
}