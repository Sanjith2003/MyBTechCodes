#include <stdio.h>
#define N 5
struct Mempos{
    char name;
    int size;
    int arr[N];
};


void FirstFit(struct Mempos mp[],int n,int m,int p[]){
    for(int i = 0;i < m;i++){
        int temp = p[i];
        for(int j = 0;j < n;j++){
            if(mp[j].size - temp >= 0){
                for(int k = 0;k < N;k++){
                    if(mp[j].arr[k] == 0){
                        mp[j].arr[k] = temp;
                        mp[j].size = mp[j].size - temp;
                        break;
                    }


                }
                break;
            }
        }
    }
}

void show_details(struct Mempos mp[],int n){
    printf("Name\t\tSize\t\tContents\n");
    for(int i = 0;i < n;i++){
        printf("%c\t\t%d\t\t",mp[i].name,mp[i].size);
        for(int j = 0;j < N;j++){ 
            printf("%d - ",mp[i].arr[j]);
        }
        printf("\n");
    }

}

int main(){
    int m;
    printf("Enter total number of processes: ");
    scanf("%d",&m);
    int p[m];
    for(int i = 0;i < m;i++){
        printf("Enter size of the process: ");
        scanf("%d",&p[i]);
        getchar();
    }
    printf("Enter total number of memory positions: ");
    int n;
    scanf("%d",&n);
    getchar();
    struct Mempos mp[n];
    for(int i = 0;i < n;i++){
        printf("Enter the name and size of the memory block: ");
        scanf("%c %d",&mp[i].name,&mp[i].size);
        
        
        for(int j = 0;j < N;j++)
            mp[i].arr[j] = 0;
        getchar();
    }
    FirstFit(mp,n,m,p);

    show_details(mp,n);
    return 0;
}
