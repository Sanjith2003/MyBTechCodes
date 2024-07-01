#include <stdio.h>


char arr[][2] = {"P1","P2","P3","P4","P5"};
int alloc[][4] = {{0,0,1,2},
                    {1,0,0,0,},
                    {1,3,5,4},
                    {0,6,3,2},
                    {0,0,1,4}};

int max[][4] = {
                {0,0,1,2},
                {1,7,5,0},
                {2,3,5,6},
                {0,6,5,2},
                {0,6,5,6}
                };

int ava[] = {1,5,2,0};

void bankers(){
    int arr1[5] = {0,0,0,0,0};
    int ind = 0;
    int need[5][4];
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 4;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }


    int term = 0;
    int flag[5] = {0,0,0,0,0};
    while(1){
        for(int i = 0;i < 5;i++){
            if(flag[i] == 0){
                int f = 0;
                for(int j = 0;j < 4;j++){
                    if(ava[j] > need[i][j]){
                        f++;
                        printf("%d\n",f);
                    }
                    else
                        break;
                    
                }
                if(f == 4){
                    term++;
                    flag[i] = 1;
                    for(int k = 0;k < 4;k++)
                        ava[k] += alloc[i][k];
                }
                arr1[ind++] = i;

            }
        
        }
           if(term == 0){
                printf("DEAD LOCK STATE\n");
                break;
            }
            else if(term == 5){
                printf("Safe seq: ");
                for(int l = 0;l < 5;l++)
                    printf("%s -> ",arr[arr1[l]]);
                    break;
            }

    }


    /*for(int i = 0;i < 5;i++){
        for(int j = 0;j < 4;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");*/
}


int main(){
    bankers();
    return 0;
}