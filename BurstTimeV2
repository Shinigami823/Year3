#include <stdio.h>

int main() {
    int numProcess;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcess);
    int burstTime[numProcess];
    int waitingTime[numProcess];
    int turnaroundTime[numProcess+1];
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;
    for (int i = 0; i < numProcess; i++) {
        printf("Enter the burst time for process %d: ", (i+1));
        scanf("%d", &burstTime[i]);
    }
    printf("%-20s%-20s%-20s%-20s\n", "Process", "Burst Time", "Waiting Time", "Turnaround Time");
    turnaroundTime[0] = burstTime[0];
    for (int i = 1; i < numProcess; i++) {
        turnaroundTime[i] = turnaroundTime[i-1] + burstTime[i];
    }
    for (int i = 0; i < numProcess; i++) {
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("%-20d%-20d%-20d%-20d\n", (i+1), burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    double avgWaitingTime = totalWaitingTime/numProcess;
    double avgTurnaroundTime = totalTurnaroundTime/numProcess;
    printf("Average Waiting Time: %f\n", avgWaitingTime);
    printf("Average Turnaround Time: %f\n", avgTurnaroundTime);
    return 0;
}
