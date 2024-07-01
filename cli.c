#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define SHMSZ 27

int main(){
    int shmid;
    char *shm,*s;
    key_t key;
    key = 5678;

    shmid = shmget(key,SHMSZ,0666);
    if(shmid < 0){
        perror("Error");
        exit(1);
    }
    shm = shmat(shmid,NULL,0);
    if(shm == (char*)-1){
        perror("Error");
        exit(1);
    }
    printf("Client is reading from the memory: \n");
    for(s = shm;*s != '\0';s++){
        putchar(*s);
        putchar('\t');
    }

    for(s = shm;*s != 'i';s++){
        *s = '*';
        exit(0);
    }
    return 0;
}
