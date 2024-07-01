#include <stdio.h>

struct Process {
    int arrivalTime;
    int burstTime;
};

void SRTF(struct Process arr[], int n) {
    int burst_time[10], temp[10];
    int i, smallest, count = 0, time;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;

    for (i = 0; i < n; i++) {
        burst_time[i] = arr[i].burstTime;
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;

    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (arr[i].arrivalTime <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;

        if (burst_time[smallest] == 0) {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arr[smallest].arrivalTime - temp[smallest];
            turnaround_time = turnaround_time + end - arr[smallest].arrivalTime;
        }
    }

    average_waiting_time = wait_time / n;
    average_turnaround_time = turnaround_time / n;

    printf("\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
}

int main() {
    struct Process processes[] = {{3,11},{0,5},{1,2},{5,12},{4,9}};
    int n = sizeof(processes) / sizeof(processes[0]);

    SRTF(processes, n);

    return 0;
}
