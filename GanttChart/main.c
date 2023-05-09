#include <stdio.h>
#include <stdlib.h>
#include "moreFunctions.h" //The struct variable for this assignment, and all additional functions are defined in this header file
#include "string.h"

int main(void) {
    int numOfTasks;
    char userResponse[3];
    char postUserResponse[5] = "null";
    char buffer[5];

    printf("Welcome to the Gantt Generator\n");
    printf("Would you like to use the test example or create your own Gantt from scratch? (Yes or No)\n");
    fgets(userResponse, 4, stdin);
    fpurge(stdin); //Clears the stdin file.

    if (strcmp(userResponse, "Yes") == 0) {
        numOfTasks = 10; //Initialised number of tasks to ten, when sample chart option is selected.
        sampleChart(ganttInput);
        printChart(ganttInput, numOfTasks);
    }
    else
    {
        printf("How many tasks would you like to add? (1-10)\n");
        fgets(buffer, 5, stdin);
        numOfTasks = atoi(buffer); //Storing the number of tasks

        userDefineChart(numOfTasks);
    }

    while (strcmp(postUserResponse, "quit") != 0) {

        printf("\nIf you wish to edit the Gantt please type \"edit\" / If you wish to run a test, "
               "type \"test\" or to exit, type \"quit\" and then press enter to execute your option.\n");
        fgets(buffer, 5, stdin);
        sscanf(buffer, "%s", postUserResponse);
        fpurge(stdin); //Clears the stdin file.

        if (strcmp(postUserResponse, "edit") == 0) {
            editChart(ganttInput, numOfTasks);
        }
        else if (strcmp(postUserResponse, "test") == 0) {
            test(ganttInput, numOfTasks);
        }
        else if (strcmp(postUserResponse, "quit") == 0) {
            printChart(ganttInput, numOfTasks);
        }
        else {
            printf("Input not recognised.\n");
        }
    }

    asciiArt();
    return 0;
}





