#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    // pid_t id;
    // id = getpid();
    printf("PID Before: %d\n",getpid());
    fork();
    printf("\nPID After: %d\n",getpid());

    return 0;
}