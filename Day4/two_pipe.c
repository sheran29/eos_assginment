#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    unsigned int fdin[2], fdout[2];
    ssize_t bytes_read, bytes_write;
    pid_t id;
    char read_m1[100], read_m2[100];
    char child_msg[] = {"I am flying\n"};
    char parent_msg[] = {"Where are you?\n"};

    pipe(fdin);
    pipe(fdout);

    id = fork();

    if(id == 0)
    {		// child process
        close(fdin[1]);
        close(fdout[0]);
        bytes_read = read(fdin[0],read_m1,sizeof(read_m1));
        printf("\nData bytes received--> %ld",bytes_read);
        printf("\nMessage received--> %s",read_m1);
        bytes_write = write(fdout[1],child_msg,sizeof(child_msg));
    }
    else
    {		// parent process
        close(fdin[0]);
        close(fdout[1]);
        bytes_write = write(fdin[1],parent_msg,sizeof(parent_msg));
        printf("Data bytes write--> %ld\n",bytes_write);
        bytes_read = read(fdout[0],read_m2,sizeof(read_m2));
        printf("Message received by parent--> %s",read_m2);
    }
    return 0;
}
