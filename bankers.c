#include <stdio.h>

int main()
{
    int num_processes, num_resources, i, j, k;
    num_processes = 5; 
    num_resources = 4; 

    int allocated[5][4] = { { 0, 0, 1, 2 },
                            { 1, 0, 0, 0 },
                            { 1, 3, 5, 4 },
                            { 0, 6, 3, 2 },
                            { 0, 0, 1, 4 } };

    int max[5][4] = { { 0, 0, 1, 2 },
                        { 1, 7, 5, 0 },
                        { 2, 3, 5, 6 },
                        { 0, 6, 5, 2 },
                        { 0, 6, 5, 6 } };

    int available[4] = { 1, 5, 2, 0 };

    int finish[num_processes], safe_sequence[num_processes], index = 0;

    for (k = 0; k < num_processes; k++) {
        finish[k] = 0;
    }

    int need[num_processes][num_resources];

    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    int resource_check = 0;

    for (k = 0; k < num_processes; k++) {
        for (i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    safe_sequence[index++] = i;
                    for (resource_check = 0; resource_check < num_resources; resource_check++) {
                        available[resource_check] += allocated[i][resource_check];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    int is_safe = 1;

    for (i = 0; i < num_processes; i++) {
        if (finish[i] == 0) {
            is_safe = 0;
            printf("The system is not safe.\n");
            break;
        }
    }

    if (is_safe == 1) {
        printf("The following is the SAFE Sequence:\n");
        for (i = 0; i < num_processes - 1; i++) {
            printf(" P%d ->", safe_sequence[i]);
        }
        printf(" P%d\n", safe_sequence[num_processes - 1]);
    }

    return 0;
}
