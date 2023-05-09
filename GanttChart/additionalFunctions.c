#include <stdio.h>
#include "moreFunctions.h"
#include "string.h"
#include "stdbool.h"


void getMonth(int x) {
    typedef enum {January, February, March,
        April, May, June, July,
        August, September, October,
        November, December} month;

    switch(x)
    {
        case(January):
            printf("  January  ");
            break;
        case(February):
            printf(" February  ");
            break;
        case(March):
            printf("   March   ");
            break;
        case(April):
            printf("   April   ");
            break;
        case(May):
            printf("    May    ");
            break;
        case(June):
            printf("   June    ");
            break;
        case(July):
            printf("   July    ");
            break;
        case(August):
            printf("  August   ");
            break;
        case(September):
            printf(" September ");
            break;
        case(October):
            printf("  October  ");
            break;
        case(November):
            printf(" November  ");
            break;
        case(December):
            printf(" December  ");
            break;
        default:
            break;

    }
}

void editChart(ganttFeatures ganttInput[10], int numOfTasks) {
    char taskName[50], input[50];
    int id = -1;
    bool validTaskName = false; //Variable used for error handling.

    while (validTaskName == false) {
        printf("Please enter the task name you want to change exactly: ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", taskName);

        for (int i = 0; i < numOfTasks; i++) {  //Locating the id (position number) of the inserted task in the struct array.
            if (strcmp(taskName, ganttInput[i].task) == 0) {
                id = i;
            }
        }

        if (id != -1) { //If id value is changed from its initialised value, then taskName was found in the array.
            validTaskName = true;
        }
        else {
            printf("Task not found!\n");
        }
    }

    printf("Please enter the new task name or write its old one: ");
    fgets(input, 50, stdin);
    sscanf(input, "%s", ganttInput[id].task);

    printf("Start month (1-12): ");
    fgets(input, 50, stdin);
    sscanf(input, "%d", &ganttInput[id].startMonth);

    printf("End month (1-12): ");
    fgets(input, 50, stdin);
    sscanf(input, "%d", &ganttInput[id].endMonth);

    printf("Number of dependencies: ");
    fgets(input, 50, stdin);
    sscanf(input, "%d", &ganttInput[id].dependencies);

    for (int j = 0; j < ganttInput[id].dependencies; j++) {
        printf("Dependent task %d: ", j + 1);
        fgets(input, 50, stdin);
        sscanf(input, "%d", &ganttInput[id].dependentTask[j]);
    }

}



void printChart(ganttFeatures ganttInput[10], int numOfTasks) {
    int i, k, monthCount, dependencyCount, m;
    unsigned long int j;

    //Prints first line of the chart.
    for (i=0; i<180; i++) {
        printf("_");
    }
    printf("\n");
    for (i=0; i<20; i++) {
        printf(" ");
    }
    for (i=0; i<12; i++) {
        printf("|");
        getMonth(i); //prints month
    }
    printf("| Dependencies \n");
    for (i=0; i<180; i++) {
        printf("=");
    }
    printf("\n");

    for (i=0; i<numOfTasks; i++) //The function prints each row of the Gantt one at a time:
    {
        printf("%s", ganttInput[i].task);

            for (j=(strlen(ganttInput[i].task)); j<20; j++) {
                printf(" ");
            }
            printf("|");


        monthCount = 1; //prints the time scheduled for the task:
        while (monthCount <= ganttInput[i].startMonth) {
            if (monthCount == ganttInput[i].startMonth) {
                for (k = ganttInput[i].startMonth; k <= ganttInput[i].endMonth; k++) {
                    printf("    XXX    |");
                }
            }
            else {
                printf("           |");
            }
            monthCount++;
        }

        for (m = 0; m < (12 - ganttInput[i].endMonth); m++) {
            printf("           |");
        }

        //prints the dependent tasks:
        if (ganttInput[i].dependencies > 0) {
            for (dependencyCount=0; dependencyCount<ganttInput[i].dependencies; dependencyCount++) {
                printf(" %d", ganttInput[i].dependentTask[dependencyCount]);
            }
        }
        for (m=0; m < 14 - 2*(ganttInput[i].dependencies); m++) {
            printf(" ");
        }


        printf("\n");
        for (m=0; m<180; m++) {
            printf("-");
        }
        printf("\n");
    }

}




int test(ganttFeatures ganttInput[10], int numOfTasks) { //This function will take in the user input, and call the printDependentTasks function:
    int visitedTasks[10] = {0}; // Initialize array of visited nodes to all 0s
    char input[50], taskName[50];
    bool validTaskName = false;
    int taskID = -1;

    //Loop for receiving the task name for test:
    while (validTaskName == false) {
        printf("Please enter the task name you want to test\n");
        fgets(input, 50, stdin);
        sscanf(input, "%s", taskName);

        for (int i = 0; i < numOfTasks; i++) {
            if (strcmp(taskName, ganttInput[i].task) == 0) {
                taskID = i;
            }
        }

        if (taskID != -1) //If the taskID was found:
        {
            validTaskName = true;
        }
        else
        {
            printf("Task not found!\n");
        }
    }

    if (check_dependent_tasks(ganttInput, taskID, visitedTasks) == 0) { //If no warnings are detected:
        printf("\nTask Path is safe. No warnings detected.\n");
    }

    return 0;
}



int check_dependent_tasks(ganttFeatures ganttInput[10], int taskID, int visited[]) {
    int ret = 0; //Stores temporary return value for the function.

    printf(" %d", taskID+1); //Printing current task id, (task number)
    visited[taskID] = 1; //Sets the current node to one.

        for (int i=0; i < ganttInput[taskID].dependencies; i++) { // Loop through all dependent tasks

            int dependentTaskID = ganttInput[taskID].dependentTask[i] - 1; //Setting dependent task id.

            if (visited[dependentTaskID] == 0) {    // If dependentTask is not already visited:
                 printf(" ->"); //then it can be printed in the path.
                 ret = check_dependent_tasks(ganttInput, dependentTaskID, visited);  //Recursive call to check the further
                                                                                           // dependent tasks of the current dependent task.
            }
            else { //If an already visited node is detected then:
                printf("\n!!!!!!!! warning potential circular dependency !!!!!!!!\n");
                int warningTask = dependentTaskID; //Variable to be used in the detect_Circular_Dependency function.
                if (detect_Circular_Dependency(ganttInput, dependentTaskID, warningTask) == 1) { //Checking for Circular Dependency.
                    printf("!!! Circular Dependency Found !!!\n");
                }
                else {
                    printf("No circular dependency found.\n");
                }


                return 1;
            }
        }

        return ret;
}

// DFS algorithm to detect cycles in a directed graph
int detect_Circular_Dependency(ganttFeatures ganttInput[10], int dependentTaskID, int warningTask) {

    int ret =0; //Stores temporary return value for the function.
    for (int i =0; i< ganttInput[dependentTaskID].dependencies; i++) {
        int dependent_task = ganttInput[dependentTaskID].dependentTask[i] - 1;

        if (dependent_task == warningTask) {
            //The dependent task found is the same as the warning task (i.e. parent/original task),
            // therefore a circular path is found.
            return 1;
        }

        //If the dependent task, is different to the warningTask, then circular dependency is not yet detected.
        //Recursive call to this function, to check the
        // further dependent tasks of the current dependent task found.
        ret = detect_Circular_Dependency(ganttInput, dependent_task, warningTask);

    }

    return ret;
}




