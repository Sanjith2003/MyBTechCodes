#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void FCFS(int arr[],int n,int h){
    int seek = 0;
    printf("Order: ");
    for(int i = 0;i < n;i++){
        if(i != n-1)
            printf("%d -> ",arr[i]);
        else
            printf("%d\n",arr[i]);
        if(i == 0)
            seek = abs(h - arr[0]);
        else{
            seek = seek + abs(arr[i-1]-arr[i]);
        }
    }
    printf("Seek time = %d\n",seek);
    printf("Avg Seek time = %f\n",(float)seek/n);
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
    FCFS(unit,n,f);
    return 0;
}