#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main()

{
    int fd1, fd2;
    char buffer[5000];

    fd1 = open("f1.txt",O_CREAT|O_WRONLY|O_RDONLY,S_IRUSR|S_IWUSR);             // New file f1 will be created
    if(fd1 == -1)
    {
        perror("Error\n");                                                      // Error handlindling if file not generated
    }

    //  write(fd1,buffer,sizeof(buffer));                                       // Write inside file f1
     write(fd1,"sheran\n",7);
    int bits=read(fd1,buffer,sizeof(buffer));                                            // Getting contents from buffer space
   
    fd2 = open("f2.txt",O_CREAT|O_WRONLY|O_RDONLY,S_IRUSR|S_IWUSR);             // New file f2 will be created
    if(fd2 == -1)
    {
        perror("Error\n");                                                      // Error handlindling if file not generated
    }
   
    write(fd2,buffer,sizeof(buffer));                                           // Copy the contents from file f1 to f2
    printf("%s\n",buffer);
    // read(fd1,buffer,sizeof(buffer)); 
    close(fd1);
    close(fd2);
}