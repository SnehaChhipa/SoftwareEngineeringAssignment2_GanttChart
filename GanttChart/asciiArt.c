#include <stdio.h>

void asciiArt() {
    printf("\n\n");
    printf("Ascii Art:\n\n"); //Our Ascii art is a video game, where the game on the screen
                              // is a music game which is displaying piano keys.

    //Prints the first three lines of the ascii art:
    for (int j=0; j<3; j++) {
        for (int i=0; i<90; i++) {
            printf("$");
        }
        printf("\n");
    }


    //Prints the next three lines:
    for (int j=0; j<3; j++) {
        for (int i=0; i<11; i++) {
            printf("$");
        }

            if (j==0) {
                printf("$$$$");
            }
            else if (j==1) {
                printf("  O ");
            }
            else {
                printf("    ");
            }


        for (int i=0; i<14; i++) {
            printf("$");
        }


        if (j == 0) {
            printf("|==$$=$$====$$=$$=$$====$$=$$|");
        }
        else {
            printf("|  $$ $$    $$ $$ $$    $$ $$|");
        }


        if (j==2) {
            for (int i=0; i<10; i++) {
                printf("$");
            }
            printf("  Y  ");
            for (int i=0; i<16; i++) {
                printf("$");
            }
        }


        else {
            for (int i=0; i<31; i++) {
                printf("$");
            }
        }
        printf("\n");
    }



    //Printing the middle line:
    for (int i=0; i<5; i++) {
        printf("$");
    }

    printf("  O     o    O  ");

    for (int i=0; i<8; i++) {
        printf("$");
    }

    printf("|  $$ $$    $$ $$ $$    $$ $$|");

    for (int i=0; i<5; i++) {
        printf("$");
    }

    printf("  X  ");

    for (int i=0; i<5; i++) {
        printf("$");
    }

    printf("  B  ");

    for (int i=0; i<11; i++) {
        printf("$");
    }

    printf("\n");



    //Prints the next three lines:
    for (int j=0; j<3; j++) {
        for (int i=0; i<11; i++) {
            printf("$");
        }

            if (j==2) {
                printf("$$$$");
            }
            else if (j==1){
                printf("  O ");
            }
            else {
                printf("    ");
            }


        for (int i=0; i<14; i++) {
            printf("$");
        }



        if (j == 2) {
            for (int i = 0; i < 30; i++) {
                if (i==0 || i==29) {
                    printf("|");
                }
                else {
                    printf("=");
                }
            }
        }
        else {
            if (j==0)
            {
                printf("|  $$ $$    $$ $$ $$    $$ $$|");
            }
            else {
                printf("|                            |");
            }
        }



        if (j==0) {
            for (int i=0; i<10; i++) {
                printf("$");
            }
            printf("  A  ");
            for (int i=0; i<16; i++) {
                printf("$");
            }
        }
        else {
            for (int i=0; i<31; i++) {
                printf("$");
            }
        }

        printf("\n");
    }




    //Prints the final three lines:
    for (int j=0; j<3; j++) {
        for (int i=0; i<90; i++) {
            printf("$");
        }
        printf("\n");
    }

}
