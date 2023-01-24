#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
    {
        // int fd;
        // char buff[1000];
        
        pid_t id;
        //printf("Parent id: %d",getppid());
        //printf("\nCurrent id: %d\n",getpid());

        id = fork();

        if(id == 0)
        {           //Child
        	//exit(0);
            printf("Its a child process\n");
            printf("\nParent id child: %d",getppid());
            printf("\nChild id child: %d\n",getpid());
        }
        else
        {           //Parent
	    sleep(10);
            printf("\nIts a parent process\n");
            printf("\nParent id of parent: %d",getppid());
            printf("\nChild id parent: %d\n",getpid());

        }

        return 0;
    }
