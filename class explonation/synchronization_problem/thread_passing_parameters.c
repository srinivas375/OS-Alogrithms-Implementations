//thread prints 0 to 3 and main process creates 20 to 24
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void * thread_function(void *arg);
int i,j;
void main()
{
  int a[]={4,80};
  void *res;
  pthread_t a_thread;//thread declaration
  pthread_create(&a_thread,NULL,thread_function,(void *)a);//thread is created
  pthread_join(a_thread,&res);//process waits for thread to finish 
  printf("%ld",(intptr_t)res);
  printf("inside main\n");
  for(j=20;j<25;j++)
  {
    printf("%d\n",j);
    sleep(1);
  }
}
void *thread_function(void *arg)
{
 printf("inside thread\n");
 int *n=arg;
 int s=n[0]+n[1];
  for(i=0;i<n[0];i++)
  {
    printf("%d\n",i);
    sleep(1);
  }
  pthread_exit((void *)(intptr_t)s);
}
 

