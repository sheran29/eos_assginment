#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <errno.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()

{
    int fd;
    unsigned char buf[128];

    fd = open("helloS_Y.txt",O_WRONLY);
    write(fd,"Welcome to cdac.\n",17);
    if(fd == -1)
    {
        perror("Error");
    }
    
    close(fd);

    return 0;
}