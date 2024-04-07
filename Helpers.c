#include "Helpers.h"

int MenuOperation(){
    int z;
    //Checking that input is an integer number to avoid bugs
    if (scanf("%d", &z) != 1) {
        printf("\nInvalid input enter a number from the menu (1 ~6) :");

        while (getchar() != '\n');


        while (scanf("%d", &z) != 1) {
            printf("\nInvalid input enter a number from the menu (1 ~6) : ");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }
    return z;
}

//============================================================
int ReadPositive() {
    int y = 1, x;
    int numScanned;

    while (y == 1) {

        numScanned = scanf("%d", &x);

        if (numScanned != 1 || x <= 0) {

            while (getchar() != '\n');

            printf("\nEnter a positive integer please: ");
        } else {
            break; // Exit the loop
        }
    }
    return x;
}
//===================================================
int ReadPositiveandZero(){

    int y = 1 , x;

    while (y == 1) {
        if (scanf("%d", &x) != 1){
            printf("Invalid input (You must enter an integer value)!");
            return 1 ;
            break ;
        }

        if (x < 0 ) {
            printf("\nEnter a positive number please : ");
        }else{
            y = 0;
        }
    }
    return x;
}
