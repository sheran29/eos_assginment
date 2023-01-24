#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd[2];
    pid_t id;
    ssize_t nbytes_read;
    ssize_t nbytes_write;
    unsigned char buff[128];

    pipe(fd);
    id = fork();

    if(id == 0)
    {
        // Child process
        close(fd[1]);
        nbytes_read = read(fd[0],buff,11);
        printf("\nNumber of bytes received: %ld",nbytes_read);
        printf("\nSent data: %s",buff);
        close(fd[0]);
    }
    else
    {	// Parent process
        close(fd[0]);
        nbytes_write = write(fd[1],"\nHello cdac\n",11);
        printf("\nNumber of bytes send: %ld\n",nbytes_write);
        close(fd[1]);
    }
}
