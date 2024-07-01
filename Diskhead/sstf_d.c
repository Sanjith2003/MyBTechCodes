#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void doSort(int arr[],int n){
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j > 0;j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
}

void SSTF(int unit[], int n, int h) {
    doSort(unit, n);

    int seek = 0;
    printf("%d -> ", h);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int current = h;
    int count = 0;
    while (count < n) {
        int minDist = INT_MAX;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && abs(unit[i] - current) < minDist) {
                minDist = abs(unit[i] - current);
                index = i;
            }
        }

        visited[index] = 1;
        seek += minDist;
        current = unit[index];

        if (count < n - 1) {
            printf("%d -> ", current);
        } else {
            printf("%d\n", current);
        }

        count++;
    }

    printf("Seek time = %d\n", seek);
    printf("Avg Seek time = %f\n", (float)seek / n);
}


int main(){
    int n;
    printf("Enter total number of units: ");
    scanf("%d",&n);
    int f;
    printf("Enter the head position: ");
    scanf("%d",&f);
    int unit[n];
    printf("Enter all the units: ");
    for(int i = 0;i< n;i++)
        scanf("%d",&unit[i]);
    SSTF(unit,n,f);
    return 0;
}