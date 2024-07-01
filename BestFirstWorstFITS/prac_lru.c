#include <stdio.h>
#include <limits.h>
int index1(int frames[],int pages[],int m,int n,int curr){
    int ind = 0;
    int md = INT_MIN;
    for(int i = 0;i < n;i++){
        int d = 0;
        for(int j = curr-1;j >=0 ;j--){
            if(pages[j] != frames[i])
                d++;
            else
                break;
        }
        if(d > md){
            md = d;
            ind = i;
        }
    }
    return ind;
}
int search(int frames[],int n,int s){
    int tar = 0;
    for(int i = 0;i < n;i++){
        if(frames[i] == s){
            return 1;
        }
    }
    return 0;

}

void LRU(int frames[],int pages[],int m,int n){
    int miss = 0;
    int hit = 0;
    for(int i = 0;i < n;i++){
        frames[i] = -1;
    }
    for(int i = 0;i < m;i++){
        printf("%d: ",pages[i]);
        if(search(frames,n,pages[i]) == 1){
            for(int j = 0;j < n;j++){
                printf("%d ",frames[j]);
            }
            hit++;
            printf(" HIT\n\n");
        }
        else{
            miss++;
            int t = 0;
            for(int j = 0;j < n;j++){
                if(frames[j] == -1){
                    frames[j] = pages[i];
                    t = 1;
                    break;
                }
            }
            if(t == 0){
                int ind = index1(frames,pages,m,n,i);
                frames[ind] = pages[i];
            }
            for(int j = 0;j < n;j++){
                printf("%d ",frames[j]);
            }
            printf("MISS\n\n");
        }
    }
    printf("MISS = %d HIT = %d",miss,hit);
    
}

int main(){
    int n; //no of frames
    printf("Enter number of frames: ");
    scanf("%d",&n);
    int frames[n];
    int m; //no of pages
    printf("Enter number of pages: ");
    scanf("%d",&m);
    int pages[m];
    printf("Enter the pages: ");
    for(int i = 0;i < m;i++){
        scanf("%d",&pages[i]);
    }
    LRU(frames,pages,m,n);
    return 0;
}