#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int miss = 0;
int hit = 0;

int findOptimal(int ele[], int fr[], int n, int index, int m) {
    int res = -1, farthest = index;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = index; j < m; j++) {
            if (fr[i] == ele[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == m)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void Optimal(int e, int arr[], int n, int ele[], int m) {
    bool hitFlag = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            hitFlag = true;
            break;
        }
    }
    
    if (hitFlag) {
        hit++;
    } else {
        miss++;
        int j = findOptimal(ele, arr, n, 0, m);
        arr[j] = e;
    }
    
    printf("Element = %d\n", e);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    if (hitFlag)
        printf("\nHIT");
    else
        printf("\nMISS");
        
    printf("\n\n");
}

int main() {
    int N, m;
    printf("Enter total number of frames: ");
    scanf("%d", &N);
    
    int fr[N];
    for (int i = 0; i < N; i++) {
        fr[i] = -1;
    }
    
    getchar();
    printf("Enter total number of elements: ");
    scanf("%d", &m);
    
    int ele[m];
    printf("Enter the elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &ele[i]);
    }
    
    for (int i = 0; i < m; i++) {
        Optimal(ele[i], fr, N, ele, m);
    }
    
    printf("HIT = %d\n", hit);
    printf("MISS = %d\n", miss);
    printf("HIT RATIO = %f\n", (float)hit / (hit + miss));
    printf("MISS RATIO = %f\n", (float)miss / (hit + miss));

    return 0;
}
