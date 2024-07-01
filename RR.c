#include <stdio.h>

struct Process {
    int processID;
    int burstTime;
    int arrivalTime;
    int remainingTime;
};

void RoundRobin(struct Process arr[], int n, int timeQuantum) {
    int i, total = 0, x, counter = 0;
    int waitTime = 0, turnaroundTime = 0;
    
    for (i = 0; i < n; i++) {
        arr[i].remainingTime = arr[i].burstTime;
    }
    
    printf("\nProcessID\tBurstTime\tTurnaroundTime\tWaitingTime\n");
    
    for (total = 0, i = 0, x = n; x != 0;) {
        if (arr[i].remainingTime <= timeQuantum && arr[i].remainingTime > 0) {
            total += arr[i].remainingTime;
            arr[i].remainingTime = 0;
            counter = 1;
        }
        else if (arr[i].remainingTime > 0) {
            arr[i].remainingTime -= timeQuantum;
            total += timeQuantum;
        }
        
        if (arr[i].remainingTime == 0 && counter == 1) {
            x--;
            printf("Process-%d\t%d\t\t%d\t\t%d\n", arr[i].processID, arr[i].burstTime,
                   total - arr[i].arrivalTime, total - arr[i].arrivalTime - arr[i].burstTime);
            waitTime += total - arr[i].arrivalTime - arr[i].burstTime;
            turnaroundTime += total - arr[i].arrivalTime;
            counter = 0;
        }
        
        if (i == n - 1)
            i = 0;
        else if (arr[i + 1].arrivalTime <= total)
            i++;
        else
            i = 0;
    }
    
    float averageWaitTime = waitTime * 1.0 / n;
    float averageTurnaroundTime = turnaroundTime * 1.0 / n;
    printf("\nAverage Waiting Time: %f", averageWaitTime);
    printf("\nAverage Turnaround Time: %f\n", averageTurnaroundTime);
}

int main() {
    int i, limit, timeQuantum;
    
    printf("Enter Total Number of Processes: ");
    scanf("%d", &limit);
    
    struct Process processes[limit];
    
    for (i = 0; i < limit; i++) {
        printf("\nEnter Details of Process-%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].processID = i + 1;
    }
    
    printf("\nEnter Time Quantum: ");
    scanf("%d", &timeQuantum);
    
    RoundRobin(processes, limit, timeQuantum);
    
    return 0;
}
