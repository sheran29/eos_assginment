#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()

{
    pid_t id1;

    id1 = fork();

    

    if(id1==0)
    {
        printf("Child");
        printf("\n PID Parent: %d\n",getppid());
        printf("\n PID Child: %d\n",getpid());
    }
    else
    {
        printf("Parent");
        printf("\nPID Parent: %d\n",getpid());
        printf("\nPID Child: %d\n",id1);
    }
}