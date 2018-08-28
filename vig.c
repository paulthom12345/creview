/* Vigenere done in c by Deborah Thompson
User includes key at startup of the program
Is prompted to put in a text to encipher
The program returns the cipher
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// declaring global variables
string key;
string plain_text;
// an array
int main(int argc, string argv[])
{
    /*Check that there is only one argument put in.
    Do not accept more than one key word
    */
    if (argc != 2)
    {
        printf("Usage: ./vigenere k \n");
        printf("Make sure only one key word is entered \n");
        return 1;
    }
    //Check that the key is only alpha characters
    key = (argv[1]);
    for (int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./vigenere key \n");
            printf("Cannot use not alphabetic characters in key\n");
            return 1;
        }
    }
    // get plain text
    {
        plain_text = get_string("Enter your sentence to be encoded: \n");
        printf("ciphertext: ");
    }
    // Determine the interval by which the plain text is to be moved
    for (int i = 0, j = 0, n = strlen(plain_text), k = strlen(key); i < n; i++)
    {
        int codeslide = tolower(key[j % k]) - 'a';
        if (isalpha(plain_text[i]))
            // Keep the case of the plain text when encoding.
        {
            if isupper(plain_text[i])
            {
                printf("%c", ((plain_text[i]) - 'A' + codeslide) % 26 + 'A');
                j++;
            }
            else if islower(plain_text[i])
            {
                printf("%c", ((plain_text[i]) - 'a' + codeslide) % 26 + 'a');
                j++;
            }
        }
        /* if it is not an alpha character return the plain text
        character but do not move forward in the cipher
        */
        else if (!isalpha(plain_text[i]))
        {
            printf("%c", plain_text[i]);
        }
    }
    {
        printf("\n");
        return 0;
    }
}

