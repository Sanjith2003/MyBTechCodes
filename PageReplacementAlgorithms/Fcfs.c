#include <stdio.h>

int miss = 0;
int hit = 0;

int in = 0;

void FCFS(int e,int arr[],int n){
    int t = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] == e){
            t = 1;
            break;
        }
    }
    if (t == 1)
        hit++;
    else{
        miss++;
        arr[in] = e;
        in = (in + 1)%n;


    }
    printf("Element = %d\n",e);
    for(int i = 0;i < n;i++)
        printf("%d ",arr[i]);
    if (t == 0)
        printf("\nMISS");
    else
        printf("\nHIT");
    printf("\n\n");
}

int main(){
    int N,m;
    printf("Enter total number of frames: ");
    scanf("%d",&N);
    int fr[N];
    for(int i = 0;i < N;i++)
        fr[i] = -1;
    getchar();
    printf("Enter total number of elements: ");
    scanf("%d",&m);
    int ele[m];
    printf("Enter the elements: ");
    for(int i = 0;i < m;i++)
        scanf("%d",&ele[i]);
    for(int i = 0;i < m;i++)
        FCFS(ele[i],fr,N);

    printf("HIT = %d\n",hit);
    printf("MISS = %d\n",miss);
    printf("HIT RATIO = %f\n",(float)hit/(hit+miss));
    printf("MISS RATIO = %f\n",(float)miss/(hit+miss));

    return 0;

}