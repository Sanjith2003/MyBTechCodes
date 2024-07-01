#include <stdio.h>

struct job {
    char name;
    int bt; 
    int at; 
    int pr; 
    int rt; 
};

void Preemptive_Priority(struct job jobs[], int n) {
    int currentTime = 0;
    int completed = 0;
    int turnaroundTime[n];
    int waitingTime[n];

    int totalBurstTime = 0;
    for (int i = 0; i < n; i++) {
        totalBurstTime += jobs[i].bt;
    }

    while (completed < n) {
        int smallestPriority = 9999;
        int selectedJob = -1;

        for (int i = 0; i < n; i++) {
            if (jobs[i].at <= currentTime && jobs[i].rt > 0 && jobs[i].pr < smallestPriority) {
                smallestPriority = jobs[i].pr;
                selectedJob = i;
            }
        }

        if (selectedJob == -1) {
            currentTime++;
            continue;
        }
        int remainingTime = jobs[selectedJob].rt;
        int executionTime = remainingTime < 2 ? remainingTime : 2;
        jobs[selectedJob].rt -= executionTime;
        currentTime += executionTime;
        if (jobs[selectedJob].rt == 0) {
            completed++;
            turnaroundTime[selectedJob] = currentTime - jobs[selectedJob].at;
            waitingTime[selectedJob] = turnaroundTime[selectedJob] - jobs[selectedJob].bt;
        }
    }

    printf("\nProcess\t\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%d\n", jobs[i].name, turnaroundTime[i], waitingTime[i]);
    }
}

int main() {
    struct job jobs[] =  {{'A',8,0,3,0},{'B',2,1,4,0},{'C',4,3,4,0},{'D',1,4,5,0},{'E',6,5,2,0},{'F',5,6,6,0},{'G',1,10,1,0}};
  

    int n = 7; 

    Preemptive_Priority(jobs, n);

    return 0;
}
