#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ 27

int main(){
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;
    if((shmid = shmget(key,SHMSZ,IPC_CREAT |0666)) < 0){
        perror("Error");
        exit(1);
    }
    shm = shmat(shmid,NULL,0);
    if(shm == (char*)-1){
        perror("Error");
        exit(1);
    }
    s = shm;

    printf("Server is writing into the memory: ");
    for(char c= 'a'; c <= 'z';c++){
        *s++ = c;
    }
    *s = '\0';

    while(*shm != '*')
        sleep(4);
    return 0;

    return 0;
}