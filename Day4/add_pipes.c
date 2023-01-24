#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    unsigned int fdin[2], fdout[2];
    pid_t id;
    ssize_t bytes_read, bytes_write;
    int x = 10 , y = 10, res = 0;

    pipe(fdin);
    pipe(fdout);

    id = fork();

    if (id == 0)
    {   //CHILD

        close(fdin[1]);
        close(fdout[0]);

        bytes_read = read(fdin[0],&x,sizeof(x));
        printf("\nBytes received--> %ld\n",bytes_read);
        res = x + y;
        bytes_write = write(fdout[1],&res,sizeof(res));
        

    }
    else
    {
        close(fdin[0]);
        close(fdout[1]);

        bytes_write = write(fdin[1],&x,sizeof(x));
        printf("\nbytes write--> %ld",bytes_write);
        bytes_read = read(fdout[0],&res,sizeof(res));
        printf("\nChild Operation result--> %d",res);
    }
}