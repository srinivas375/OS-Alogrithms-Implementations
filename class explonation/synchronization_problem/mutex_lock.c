#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int shared=2;
void *fun1();
void *fun2();
pthread_mutex_t s;
void main()
{
  pthread_mutex_init(&s,NULL);//initialize
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
  pthread_mutex_lock(&s);
  printf("\nbefore assign to x1 value of shared=%d",shared);
  x1=shared;
  x1=x1+1;
  printf("\nlocal value of x1 after increment=%d",x1);
  sleep(1);
  shared=x1;
  printf("\nthe value of shared variable after update by x1 =%d",shared);
  pthread_mutex_unlock(&s);
}
void * fun2()
{
  int x2;
  pthread_mutex_lock(&s);
  printf("\nbefore assign to x2 value of shared=%d",shared);
  x2=shared;
  x2=x2-1;
  printf("\nlocal value of x2 after decrement=%d",x2);
  sleep(1);
  shared=x2;
  printf("\nthe value of shared variable after updation by x2 =%d",shared);
  pthread_mutex_unlock(&s);
}

