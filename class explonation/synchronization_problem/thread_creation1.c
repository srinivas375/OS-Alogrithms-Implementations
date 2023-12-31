//thread prints 0 to 3 and main process creates 20 to 24
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int i,j;
void main()
{
  pthread_t a_thread;//thread declaration
  pthread_create(&a_thread,NULL,thread_function,NULL);//thread is created
  //pthread_join(a_thread,NULL);//process waits for thread to finish 
  printf("inside main\n");
  for(j=1;j<5;j++)
  {
    printf("%d\n",j);
    sleep(1);
  }
}
void *thread_function(void *args)
{
 printf("inside thread=\n");
  for(j=20;j<25;j++)
  {
    printf("%d\n",j);
    sleep(1);
  }
}
 

