#include <stdio.h>
#include <stdlib.h>

struct process{
    int no;
    int bt;
    int at;
};

void doSort(struct process arr[],int n){
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j>0;j--){
            if(arr[j].at < arr[j-1].at){
                struct process temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
        }
    }
}

void sjf(struct process arr[],int n){
    doSort(arr,n);
    int flag[n];
    int t = 0;
    for(int i = 0;i < n;i++)
        flag[i] = 0;
    int time = 0;
    printf("Process\t\tTAT\t\tWT\t\tRT\n");
    while(t != n){
        int ind = 0;
        int time = 0;
        for(int i = 0;i < n;i++){
            if(flag[i] == 0){
                if(i == 0){
                    time = arr[i].bt;
                    printf("%d\t\t%d\t\t%d\t\t%d\n",arr[i].no,time-arr[i].at,time - arr[i].bt,time - arr[i].bt);
                    t++;
                    flag[0] = 1;
                }
                else{
                    int min = arr[i].bt;
                    int ind = i;
                    for(int j = i;j < n;j++){
                        if(arr[j].at <= t){
                            if(arr[j].bt < min){
                                min = arr[j].bt;
                                ind = j;
                            }
                        }
                    }
                    time += arr[ind].bt;
                    t++;
                    flag[ind] = 0;
                    printf("%d\t\t%d\t\t%d\t\t%d\n",arr[ind].no,time - arr[ind].at,time-arr[ind].bt,time -arr[ind].bt);
                }

            }
        }
    }
    
    
}

int main(){
    struct process arr[5];
    for(int i = 0;i < 5;i++){
        arr[i].no = i+1;
        printf("Enter burst time and arrival time: ");
        scanf("%d %d",&arr[i].bt,&arr[i].at);
        getchar();
    }
    sjf(arr,5);
    return 0;
}