#include <stdio.h>
#include <stdlib.h>

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

void CSCAN(int unit[], int n, int h) {
    doSort(unit, n);

    int seek = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (unit[i] >= h) {
            index = i;
            break;
        }
    }

    printf("%d -> ", h);

    // Left direction
    for (int i = index; i >= 0; i--) {
        printf("%d -> ", unit[i]);
        seek += abs(unit[i] - h);
        h = unit[i];
    }


    // Right direction
    for (int i = n - 1; i > index; i--) {
        printf("%d -> ", unit[i]);
        seek += abs(unit[i] - h);
        h = unit[i];
    }

    printf("\nSeek time = %d\n", seek);
    printf("Avg Seek time = %f\n", (float)seek / n);
}

int main() {
    int n;
    printf("Enter total number of units: ");
    scanf("%d", &n);

    int f;
    printf("Enter the head position: ");
    scanf("%d", &f);

    int unit[n];
    printf("Enter all the units: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &unit[i]);
    }

    CSCAN(unit, n, f);

    return 0;
}

