#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char*) shmat(shmid,(void*)0,10);
	printf("Write Data : ");
	scanf("%c",&str);
	printf("Data written in memory: %c\n",str);
	shmdt(str);
	return 0;
}
