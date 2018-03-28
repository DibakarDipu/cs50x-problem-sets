/* 
.......... DIBAKAR SUTRA DHAR ...........
....... iamdibakardipu@gmail.com ........
.............. dibakar.me ...............
.........................................
............... CS50x ...................
........... PROBLEM SET 1 ...............
........ MARIO MORE COMFORTABLE .........
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, k;

    // Get Input From User
    do
    {
        printf("Please choose between 0 to 23: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    // Print Rows
    for (i = 1; i <= height; i++)
    {
        // Print spaces
        for (j = 0; j < (height - i); j++)
        {
            printf(" ");
        }

        // Print left-hand hashes
        for (k = 0; k < i; k++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right-hand hashes
        for (k = 0; k < i; k++)
        {
            printf("#");
        }

        // Print new line
        printf("\n");
    }

    return 0;
}
