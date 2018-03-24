#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //convert the key from command line into an integer
        string key = argv[1];
        int i = atoi(key);

        //prompt user for text desired to be encrypted
        string text = get_string("plaintext: ");

        printf("ciphertext: ");
        for (int j = 0, n = strlen(text); j < n; j++)
        {
            char x = text[j];
            char m;
            //check for upper or lower case and make the cipher
            if (isupper(x))
            {
                m = (x - 'A' + i) % 26;
                m = m + 'A';
                printf("%c", m);
            }
            else if (islower(x))
            {
                m = (x - 'a' + i) % 26;
                m = m + 'a';
                printf("%c", m);
            }
            //if it isn't a letter, go ahead and print as is
            else
            {
                printf("%c", x);
            }
        }
    }
    //If argc is not 2, print error
    else
    {
        printf("Error");
        return 1;
    }
    printf("\n");
    return 0;
}