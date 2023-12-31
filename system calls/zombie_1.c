#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>
int main()
{
    pid_t p;
    p = fork();
    if (p == 0) // child process
    {
        printf("hi i am child process with pid :%d\n", getpid());
        printf("my parent pid is :%d\n", getppid());
    }
    else // parent process
    {
        sleep(3);
        printf("i am a parent with pid :%d\n", getpid());
        printf("i have a child with pid :%d\n", p);
    }
    return 0;
}