/* 
.......... DIBAKAR SUTRA DHAR ...........
....... iamdibakardipu@gmail.com ........
.............. dibakar.me ...............
.........................................
............... CS50x ...................
........... PROBLEM SET 1 ...............
......... COIN CHANGE MACHINE ...........
*/

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void) {

    float change;
    int coin = 0;
    int quantity;


    // Asking for change
    do {
        printf("Please enter the quantity of Change: \n");
        change = get_float();
    } while (change < 0);

    // Converting dollars to cents
    quantity = (int) round(change * 100);


    // Calculating the quantity of coins to give
    while (quantity >= 25) {
        quantity -= 25;
        coin++;
    }

    while (quantity >= 10) {
        quantity -= 10;
        coin++;
    }

    while (quantity >= 5) {
        quantity -= 5;
        coin++;
    }

    while (quantity >= 1) {
        quantity -= 1;
        coin++;
    }

    printf("%i\n", coin);
}