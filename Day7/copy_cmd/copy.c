#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, const char * argv[])
{
    int fd1, fd2;
    unsigned char buffer[800000];
    ssize_t n,m;

    if(argc < 3)
    {
        printf("Less arguments passed!\n");
        perror("Error");
    }

    fd1 = open(argv[1], O_RDONLY,S_IWUSR|S_IRUSR);
    if(fd1==-1)
    {
        perror("ERROR1");
    }

    n=read(fd1,buffer,sizeof(buffer));
    if(sizeof(n) > sizeof(buffer))
    {
        printf("Size is too big!\n");
    }

    if(n == -1)
    {
        perror("Error2.\n");
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT,S_IWUSR|S_IRUSR);
    if(fd2==-1)
    {
        perror("ERROR3");
    }
    m = write(fd2,buffer,sizeof(buffer));
    if(sizeof(m) > sizeof(buffer))
    {
        printf("Size is too big.\n");
    }
    if(m == -1)
    {
        perror("Error4\n");
        
    }

    remove(argv[1]);
    close(fd1);
    close(fd2);
    return 0;
}
