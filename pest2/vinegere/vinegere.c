#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Get Key to the Cipher from User command line input
int main(int argc, string argv[])
{

    // Checking if aruguments are correct
    if (argc != 2)
    {
        printf("Wrong Number of Arguments. Please Try Again.\n");
        return 1;
    }

    // Checking if Entered arguments are in alphabetic
    else
    {

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be Alphabetic Characters.\n");
                return 1;
            }
        }
    }

    // Storing key as String
    string k = argv[1];

    // Getting Length
    int kLen = strlen(k);

    // Get plaintext to encode
    printf("plaintext: ");
    string plaintxt = get_string();

    // Printing ciphertext
    printf("ciphertext: ");

    // Looping through text
    for (int i = 0, j = 0, n = strlen(plaintxt); i < n; i++)
    {

        // Getting key for this letter
        int key = tolower(k[j % kLen]) - 'a';

        // Add key to Uppercase letters
        if (isupper(plaintxt[i]))
        {
            printf("%c", (((plaintxt[i] + key) - 'A') % 26) + 'A');
            j++;
        }

        // Add key to lowercase letters
        else if (islower(plaintxt[i]))
        {
            printf("%c", (((plaintxt[i] + key) - 'a') % 26) + 'a');
            j++;
        }

        // For non-letters
        else
        {
            printf("%c", plaintxt[i]);
        }
    }

    printf("\n");

    return 0;
}