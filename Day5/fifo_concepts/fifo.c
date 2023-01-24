#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()

{
    unsigned int fd[2];
    char buff[1024];
    ssize_t bytes_write;

    open("pro1.c",O_WRONLY);

    bytes_write = write(fd[1],"Hello pro1\n",11);

    close(fd[1]);
}