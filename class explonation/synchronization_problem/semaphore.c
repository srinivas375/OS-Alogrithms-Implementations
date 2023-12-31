#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
int shared=2;
void *fun1();
void *fun2();
sem_t s;
void main()
{
  sem_init(&s,0,1);
  pthread_t t1,t2;
  pthread_create(&t1,NULL,fun1,NULL);
  pthread_create(&t2,NULL,fun2,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  printf("\nfinal res=%d",shared);
}
void * fun1()
{
  int x1;
  sem_wait(&s);
  x1=shared;
  printf("\nbefore assign to x1=%d",shared);
  x1=x1+1;
  sleep(1);
  shared=x1;
  printf("\nafter  updation by x1 to the shared=%d",shared);
  sem_post(&s);
}
void * fun2()
{
  int x2;
  sem_wait(&s);
  x2=shared;
  printf("\nbefore assign to x2=%d",shared);
  x2=x2-1;
  sleep(1);
  shared=x2;
  printf("\nafter  updation by x2 to the shared=%d",shared);
  sem_post(&s);
}

