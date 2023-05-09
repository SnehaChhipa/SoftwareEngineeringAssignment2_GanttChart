#include <stdio.h>
#include "string.h"
#include "moreFunctions.h"

void sampleChart(ganttFeatures ganttInput[10]) {

    strcpy(ganttInput[0].task, "Market_Research");
    ganttInput[0].startMonth = 1;
    ganttInput[0].endMonth = 2;
    ganttInput[0].dependencies = 0;

    strcpy(ganttInput[1].task, "Sourcing_Investors");
    ganttInput[1].startMonth = 2;
    ganttInput[1].endMonth = 4;
    ganttInput[1].dependencies = 1;
    ganttInput[1].dependentTask[0] = 1;

    strcpy(ganttInput[2].task, "Business_Plan");
    ganttInput[2].startMonth = 4;
    ganttInput[2].endMonth = 5;
    ganttInput[2].dependencies = 1;
    ganttInput[2].dependentTask[0] = 2;

    strcpy(ganttInput[3].task, "Loan_Application");
    ganttInput[3].startMonth = 5;
    ganttInput[3].endMonth = 5;
    ganttInput[3].dependencies = 1;
    ganttInput[3].dependentTask[0] = 3;

    strcpy(ganttInput[4].task, "Legal_Paperwork");
    ganttInput[4].startMonth = 6;
    ganttInput[4].endMonth = 6;
    ganttInput[4].dependencies = 1;
    ganttInput[4].dependentTask[0] = 4;

    strcpy(ganttInput[5].task, "Renting_Premises");
    ganttInput[5].startMonth = 5;
    ganttInput[5].endMonth = 7;
    ganttInput[5].dependencies = 1;
    ganttInput[5].dependentTask[0] = 4;

    strcpy(ganttInput[6].task, "Renting_Equipment");
    ganttInput[6].startMonth = 8;
    ganttInput[6].endMonth = 8;
    ganttInput[6].dependencies = 1;
    ganttInput[6].dependentTask[0] = 4;

    strcpy(ganttInput[7].task, "Staff_Recruitment");
    ganttInput[7].startMonth = 8;
    ganttInput[7].endMonth = 9;
    ganttInput[7].dependencies = 2;
    ganttInput[7].dependentTask[0] = 3;
    ganttInput[7].dependentTask[1] = 5;

    strcpy(ganttInput[8].task, "Production");
    ganttInput[8].startMonth = 9;
    ganttInput[8].endMonth = 11;
    ganttInput[8].dependencies = 2;
    ganttInput[8].dependentTask[0] = 5;
    ganttInput[8].dependentTask[1] = 6;

    strcpy(ganttInput[9].task, "Distribution");
    ganttInput[9].startMonth = 11;
    ganttInput[9].endMonth = 12;
    ganttInput[9].dependencies = 1;
    ganttInput[9].dependentTask[0] = 7;
}


void userDefineChart(int numOfTasks) {
    char input[50];
    int i, j;

    for (i = 0; i < numOfTasks; i++) { //Receiving user input for each task.
        printf("%d. Please enter the task name:\n", i + 1);
        fgets(input, 50, stdin);
        sscanf(input, "%s", ganttInput[i].task);

        printf("Start month (1-12):\n");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &ganttInput[i].startMonth);

        printf("End month (1-12):\n");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &ganttInput[i].endMonth);

        printf("Enter how many dependencies this task has:\n");
        fgets(input, 50, stdin);
        sscanf(input, "%d", &ganttInput[i].dependencies);

        for (j = 0; j < ganttInput[i].dependencies; j++) {
            printf("Enter dependent task %d:\n", j + 1);
            fgets(input, 50, stdin);
            sscanf(input, "%d", &ganttInput[i].dependentTask[j]);
        }

    }

}