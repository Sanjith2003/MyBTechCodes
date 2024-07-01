#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define BS 5
#define n 10

int buf[BS];
int in = 0, out = 0;

sem_t full,empty;
pthread_mutex_t mutex;

void *producer(){
    int item;
    for(int i = 0;i < n;i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        item = rand() % 100;
        printf("Producer: %d\n",item);
        in = (in + 1)%BS;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(){
    int item;
    for(int i = 0;i < n;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buf[out];
        out = (out+1)%BS;
        printf("Consumed: %d\n",item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t prod,cons;
    sem_init(&full,0,0);
    sem_init(&empty,0,BS);
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);
    pthread_join(prod,NULL);
    pthread_join(cons,NULL);
    return 0;
}