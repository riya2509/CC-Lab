// Round Robin
/* This algorithm is designed for time sharing system where it is not necessary to complete one process 
and start another but to be responsive and divide the time of CPU among all the processes. 
Here the ready queue will be treated as a circular queue.
We fix a time quantum upto which a process can access a CPU within which either a process terminates or 
process must release the CPU and re-enter into the circular queue and wait for the next chance.*/

// Min min algorithm
/*For each task determine it's minimum completion time over all machines.
Over all tasks find the minimum completion time.
Assign the tasks to the machine that gives this completion time.
Repeat the above steps until all the tasks are getting scheduled.*/

//Max-Min algorithm
/*no.of task , no.of machine, completion time of each machine*/

#include <stdio.h>

void roundRobin(int tasks, int machines) {
    int completionTime[machines];
    int taskTime[tasks];

    // Initialize completion time and task time arrays
    for (int i = 0; i < machines; i++)
        completionTime[i] = 0;
    
    printf("Enter the execution time of each task:\n");
    for (int i = 0; i < tasks; i++)
        scanf("%d", &taskTime[i]);

    int currentTime = 0;
    int taskIndex = 0;

    // Schedule tasks using Round Robin
    while (taskIndex < tasks) {
        int machineIndex = currentTime % machines;
        if (taskTime[taskIndex] > 0) {
            printf("Task %d executed on machine %d from %d to ", taskIndex + 1, machineIndex + 1, currentTime);
            currentTime += (taskTime[taskIndex] < machines) ? taskTime[taskIndex] : machines;
            printf("%d\n", currentTime);
            taskTime[taskIndex] -= machines;
        }

        taskIndex++;
    }
}



int main(){
    int tasks, macines;

    printf("Enter the number of tasks:");
    scanf("%d", &tasks);

    printf("Enter the number of machines:");
    scanf("%d", &machines);

    roundRobin(tasks, machines);
    return 0;
}

