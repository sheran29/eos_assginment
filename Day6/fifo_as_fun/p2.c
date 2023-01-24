#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>


int main()

{
    unsigned int fd;
    char buff[1024];
    // // char message[] = {"This is a auto generated message for pro1\n"};
    // ssize_t bytes_write;

    mkfifo("desdfile",0660);

    fd=open("desdfile",O_RDONLY);
    read(fd,buff,sizeof(buff));

    printf("Received: %s",buff);

    close(fd);
    return 0;
}
