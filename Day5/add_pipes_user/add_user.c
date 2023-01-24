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
    int x, y, res = 0;

    pipe(fdin);
    pipe(fdout);

    id = fork();

    if (id == 0)
    {   //CHILD

        close(fdin[1]);
        close(fdout[0]);

        bytes_read = read(fdin[0],&x,sizeof(x));
        printf("Bytes received--> %ld\n",bytes_read);

        printf("Enter y value for addition--> ");
        scanf("%d",&y);        
        res = x + y;
        bytes_write = write(fdout[1],&res,sizeof(res));
        printf("\n");
        

    }
    else
    {
        close(fdin[0]);
        close(fdout[1]);

        printf("Enter x value for addition--> ");
        scanf("%d",&x);

        bytes_write = write(fdin[1],&x,sizeof(x));
        printf("\nbytes write--> %ld",bytes_write);
        bytes_read = read(fdout[0],&res,sizeof(res));
        printf("\nChild Operation result--> %d\n",res);
    }
    return 0;
}