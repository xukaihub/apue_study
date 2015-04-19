#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    fd = open("bar", O_RDWR);
    if (fd < 0)
        perror("open");
    if (write(fd, "This is a test file for truncate!", 33) != 33)
        perror("write");
    close(fd);

    if (truncate("bar", 19) < 0)
        perror("truncate"); 
    
    return 0;
}
