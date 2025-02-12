#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int item;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        item = rand() % 100; // Generate a random item
        sem_wait(&empty);    // Wait for an empty slot in the buffer
        pthread_mutex_lock(&mutex);
        
        buffer[in] = item;   // Produce the item and put it in the buffer
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);     // Signal that the buffer is full
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        sem_wait(&full);     // Wait for a full slot in the buffer
        pthread_mutex_lock(&mutex);
        
        item = buffer[out];  // Consume an item from the buffer
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);    // Signal that the buffer is empty
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Cleanup resources
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
