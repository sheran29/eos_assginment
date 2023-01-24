#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, char * argv[])
{
    int fd1, fd2;
    unsigned char buffer[400];
    ssize_t n;

    fd1 = open(argv[1], O_WRONLY | O_RDONLY | O_CREAT, S_IWUSR|S_IRUSR);
    if(fd1==-1)
    {
        perror("ERROR 1\n");
    }
     write(fd1,"hello\n",6);
     n=read(fd1,buffer,6);
    if(n==-1)
    {
        perror("ERROR 2\n");
    }
    fd2 = open(argv[2], O_WRONLY |O_RDONLY| O_CREAT,S_IWUSR|S_IRUSR);
    if(fd2==-1)
    {
        perror("ERROR3\n");
    }
    int m=write(fd2,buffer,sizeof(buffer));
    if(m==-1)
    {
        perror("ERROR 4\n");
    }
    printf("%s\n",buffer);
    printf("%d\n",m);
    close(fd1);
    close(fd2);
    return 0;
}
