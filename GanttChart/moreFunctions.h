
typedef struct {
    char task[50];
    int startMonth;
    int endMonth;
    int dependencies;
    int dependentTask[9];

} ganttFeatures;

ganttFeatures ganttInput[10]; //Declaring struct array.

void sampleChart(ganttFeatures ganttInput[10]); //Assigns sample input to gantt chart
void getMonth(int x); //Function to convert an integer into the corresponding month.
void userDefineChart(int numOfTasks); //Function which lets user to input the data for gantt.

void printChart(ganttFeatures ganttInput[10], int numOfTasks); //Displays gantt chart
void editChart(ganttFeatures ganttInput[10], int numOfTasks); //Edits chart according to user input

int test(ganttFeatures ganttInput[10], int numOfTasks); //A function to take user input of which task to be tested, and also to call other testing functions.
int check_dependent_tasks(ganttFeatures ganttInput[10], int taskID, int visited[]); //Loops through dependent tasks, and prints potential warning for circular dependency.
int detect_Circular_Dependency(ganttFeatures ganttInput[10], int dependentTaskID, int warningTask); //Function called if warning detected.

void asciiArt();
