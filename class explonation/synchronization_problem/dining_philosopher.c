#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopstick[10];
int size;
void *philos(void*);
void eat(int);
void main()
{
  int i;
  printf("enter number of philosophers=");
  scanf("%d",&size);
  pthread_t T[size];
  for(i=0;i<size;i++)
    sem_init(&chopstick[i],0,1);
  for(i=0;i<size;i++)
  {
    pthread_create(&T[i],NULL,philos,(void *)&i);
  }
  for(i=0;i<size;i++)
    pthread_join(T[i],NULL);
}
void * philos(void *n)
{
  int ph=*(int *)n;
  printf("Philosopher %d wants to eat\n",ph);
  printf("Philosopher %d tries to pick up left chopstick\n",ph);
  sem_wait(&chopstick[ph]);
  printf("Philosopher %d picks up left chopstick\n",ph);
  printf("Philosopher %d tries to pick up right chopstick\n",ph);
  sem_wait(&chopstick[(ph+1)%size]);
  printf("Philosopher %d picks up right chopstick\n",ph);
  eat(ph);
  sleep(2);
  printf("****Philosoper %d has finished eating****\n",ph);
  sem_post(&chopstick[(ph+1)%size]);
  printf("Philosoper %d has leaved right chopstick\n",ph);
  sem_post(&chopstick[ph]);
  printf("Philosoper %d has leaved left chopstick\n",ph);
}
void eat(int ph)
{
   printf("philosopher %d begins eating\n",ph);
}

  
  
  
  
  
  
  
    


