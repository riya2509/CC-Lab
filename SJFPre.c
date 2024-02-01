#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    bool completed;
};

void sortByArrivalTime(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void sjfPreemptive(struct Process processes[], int n) {
    int currentTime = 0;

    while (true) {
        int shortestJobIndex = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestBurst) {
                shortestBurst = processes[i].remainingTime;
                shortestJobIndex = i;
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
        } else {
            processes[shortestJobIndex].remainingTime--;
            currentTime++;

            if (processes[shortestJobIndex].remainingTime == 0) {
                processes[shortestJobIndex].completed = true;
            }

            printf("Process %d executed at time %d\n", processes[shortestJobIndex].id, currentTime);

            if (currentTime == n) {
                break;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].completed = false;

        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);

        processes[i].remainingTime = processes[i].burstTime;
    }

    sortByArrivalTime(processes, n);

    printf("\nExecution Order:\n");
    sjfPreemptive(processes, n);

    return 0;
}
