#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main()
{
    char buff[16];
    int fd;
    fd = open("desdfifo",O_RDONLY);
    read(fd,buff,16);
    printf("read: %s",buff);
    close(fd);

    return 0;
}