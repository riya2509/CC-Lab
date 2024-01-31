#include <stdio.h>

void maxMin(int tasks, int machines) {
    int completionTime[machines];
    int taskTime[tasks];

    // Initialize completion time and task time arrays
    for (int i = 0; i < machines; i++)
        completionTime[i] = 0;
    
    printf("Enter the execution time of each task:\n");
    for (int i = 0; i < tasks; i++)
        scanf("%d", &taskTime[i]);

    // Schedule tasks using Max-Min
    for (int i = 0; i < tasks; i++) {
        int maxTime = taskTime[0];
        int machineIndex = 0;

        for (int j = 1; j < machines; j++) {
            if (completionTime[j] + taskTime[j] > maxTime) {
                maxTime = completionTime[j] + taskTime[j];
                machineIndex = j;
            }
        }

        printf("Task %d executed on machine %d from %d to %d\n", i + 1, machineIndex + 1, completionTime[machineIndex], maxTime);
        completionTime[machineIndex] = maxTime;
        taskTime[machineIndex] = -1;  // Mark the task as completed
    }
}

int main() {
    int tasks, machines;

    printf("Enter the number of tasks: ");
    scanf("%d", &tasks);

    printf("Enter the number of machines: ");
    scanf("%d", &machines);

    maxMin(tasks, machines);

    return 0;
}
