#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int BUFFER_SIZE,NUM_PRODUCERS,NUM_CONSUMERS;
int buffer[10];
int in = 0;  
int out = 0;
sem_t mutex, empty, full;
void* producer(void* arg) {
        int item = 1;
        sleep(2); 
        sem_wait(&empty);
        sem_wait(&mutex);
        // Produce item and insert into buffer
        buffer[in] = item;
        printf("Producer %ld produced item %d at index %d\n", (long)arg, item, in);
        in = (in + 1) % BUFFER_SIZE;
	sem_post(&mutex);
        sem_post(&full);
        item++;
}
void* consumer(void* arg)
{
        sem_wait(&full);
        sem_wait(&mutex);
        // Consume item from buffer
        int item = buffer[out];
        printf("Consumer %ld consumed item %d from index %d\n", (long)arg, item, out);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
}

int main() 
{
    printf("enter the buffer size=");
    scanf("%d",&BUFFER_SIZE);
    printf("enter number of producers=");
    scanf("%d",&NUM_PRODUCERS);
    printf("enter number of consumers=");
    scanf("%d",&NUM_CONSUMERS);
    if(NUM_CONSUMERS<=NUM_CONSUMERS)
    {
       printf("numbers of consumers is less than or equal to number of producers");
       exit(0);
    }
    pthread_t producer_threads[NUM_PRODUCERS];
    pthread_t consumer_threads[NUM_CONSUMERS];
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    // Create producer threads
    for (long i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_create(&producer_threads[i], NULL, producer, (void*)i);
    }
    // Create consumer threads
    for (long i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_create(&consumer_threads[i], NULL, consumer, (void*)i);
    }
    int i;
    for (i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_join(producer_threads[i], NULL);
    }
    for (i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_join(consumer_threads[i], NULL);
    }
    // Cleanup
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

