#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
     {
        pid_t id;

        id = fork();

        if(id == 0)
           {
           	sleep(10);
                printf("in child process:%d\nparent id :%d\n",getpid(),getppid());
                exit(0);
            }

        else
            
		 printf("in parent process\nparent id %d\nchild id %d",getpid(),getppid());
        return 0;
     }
