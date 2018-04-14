/* 
.......... DIBAKAR SUTRA DHAR ...........
....... iamdibakardipu@gmail.com ........
.............. dibakar.me ...............
.........................................
............... CS50x ...................
........... PROBLEM SET 2 ...............
........ CAESAR LESS COMFORTABLE ........
*/



#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Get Key to the Cipher from User command line input
int main(int argc, string argv[]){

    // Check if User did not enter command line argument
    if (argc == 1) {
        printf("You did not enter any command line argument.\n");
        return 1;
    }

    // Check if user enter more than one command line arugment
    else if (argc > 2) {
        printf("You entered too many command line arugment.\n");
        return 1;
    }

    // Assume user entered only one valid command line argument
    else {

        // Convarting string key to an integer
        int key = atoi(argv[1]);

        // Getting Plaintext input from user
        printf("plaintext: ");
        string plaintxt = get_string();

        // ASCII uppercase A starts from 65
        int ascii_A = 65;

        // ASCII lowercase a starts from 97
        int ascii_a = 97;

        // Alphabet index number 26

        printf("ciphertext: ");

        // Looping through all the plain letters
        for (int i = 0, n = strlen(plaintxt); i < n; i++) {

            // Add key to Uppercase letters
            if (isupper(plaintxt[i])) {
                printf("%c", (((plaintxt[i] + key) - ascii_A) % 26) + ascii_A);
            }

            // Add key to lowercase letters
            else if (islower(plaintxt[i])) {
                printf("%c", (((plaintxt[i] + key) - ascii_a) % 26) + ascii_a);
            }

            // For non-letters
            else {
                printf("%c", plaintxt[i]);
            }
        }
    }

    printf("\n");

    return 0;

}