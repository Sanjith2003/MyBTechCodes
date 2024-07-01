#include <stdio.h>

struct job{
    char name;
    int bt;
    int at;
    int pt;
    int s;
};




void do_sort(struct job arr[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j>0;j--){
            if(arr[j].at < arr[j-1].at){
                struct job temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void Priority(struct job arr[],int n){
    float avg_t;
    float avg_w;
    printf("Job\t\tTat\t\tWt\n");
    do_sort(arr,6);
    int max = 0;
    for(int i = 0;i < n;i++){
        if(arr[i].pt > arr[max].pt)
            max = i;
    }
    int t = 0,i = 0;
    while(i < n){
        int j = 0;
        int index = max;
        while(arr[j].at <= t){
            if(arr[j].pt < arr[index].pt){
                if(arr[j].s == 0)
                    index = j;
            }
            j++;
        }
        arr[index].s = 1;
        t += arr[index].bt;
        avg_t += t - arr[index].at;
        avg_w += (t-arr[index].bt)-arr[index].at;
        printf("%c\t\t%d\t\t%d\n",arr[index].name,t - arr[index].at,(t-arr[index].bt)-arr[index].at);
        i++;

    }
    printf("Average Turn around time = %f",avg_t/n);
    printf("\nAverage Waiting time = %f",avg_w/n);
}
int main(){
    struct job jobs[] = {{'A',8,0,3,0},{'B',2,1,4,0},{'C',4,3,4,0},{'D',1,4,5,0},{'E',6,5,2,0},{'F',5,6,6,0},{'G',1,10,1,0}};
    Priority(jobs,7);
}

