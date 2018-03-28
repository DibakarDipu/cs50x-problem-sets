/* 
.......... DIBAKAR SUTRA DHAR ...........
....... iamdibakardipu@gmail.com ........
.............. dibakar.me ...............
.........................................
............... CS50x ...................
........... PROBLEM SET 1 ...............
........ CREDIT CARD VALIDATION .........
*/


#include <cs50.h>
#include <stdio.h>

int main (void) {

    long long cardNumber = 0;
    long long digits = 0;

    int digitCount = 0;
    int x = 0;
    int temp;

    // Asking the card number
    do {
        printf("Please Enter your Card Number: \n");
        cardNumber = get_long_long();
    } while (cardNumber < 0);

    // Detiremining the validity of Card
    digits = cardNumber;

    while (digits > 0) {
        digits = digits/10;
        digitCount++;
    }

    if ((digitCount != 13) && (digitCount != 15) && (digitCount != 16)) {
        printf("INVALID\n");
    }

    int number[digitCount];

    for (int i = 0; i < digitCount; i++) {
        number[i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }

    int originalNumber[digitCount];

    for (int i = 1; i < digitCount; i++) {
        originalNumber[i] = number[i];
    }

    for (int i = 1; i < digitCount; i += 2) {
        number[i] = number[i] * 2;
    }

    if (digitCount == 13) {
        for (int i = 0; i < digitCount; i++) {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            x = x + temp;
        }

        if ((originalNumber[12] == 4) && (x % 10 == 0)) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else if (digitCount == 15) {
        for (int i = 0; i < digitCount; i++) {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            x = x + temp;
        }

        if (((originalNumber[14] == 3) && (x % 10 == 0)) && ((originalNumber[13] == 4) || (originalNumber[13] == 7))) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    } else if (digitCount == 16) {
        for (int i = 0; i < digitCount; i++) {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            x = x + temp;
        }

        if ((originalNumber[15] == 4) && (x % 10 == 0)){
            printf("VISA\n");
        } else if (((originalNumber[15] == 5) && (x % 10 == 0)) && ((originalNumber[14] == 1) || (originalNumber[14] == 2) || (originalNumber[14] == 3) || (originalNumber[14] == 4) || (originalNumber[14] == 5))) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    }

    return 0;

}