#include <stdio.h>

struct Jobs{
    char name;
    int b_time;
    int a_time;
};

struct Jobs jobs[] = {{'A',2,2},{'B',1,0},{'C',3,2},{'D',5,3},{'E',4,4}};

void sort(struct Jobs jb[],int n){
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j > 0;j--){
            if(jb[j].a_time < jb[j-1].a_time){
                struct Jobs temp = jb[j];
                jb[j] = jb[j-1];
                jb[j-1] = temp;
            }
            else
                break;
        }
    }
}

void FCFS(struct Jobs jb[],int n){
    sort(jb,n);
    int T_at = 0;
    int W_t = 0;
    int R_t = 0;
    int ct = 0;
    int temp;
    for(int i = 0;i < n;i++){
        ct += jb[i].b_time;
        T_at += (ct - jb[i].a_time);
        printf("T_at of %c = %d\t",jb[i].name,ct - jb[i].a_time);
        temp = ct - jb[i].b_time;
        W_t += temp - jb[i].a_time;
        printf("W_at of %c = %d\n",jb[i].name,temp-jb[i].a_time);   
    }
    printf("Average T_at = %f\tAvergae W_at = %f\n",T_at/(5.0),W_t/(5.0));

}
int main(){
    FCFS(jobs,5);
}