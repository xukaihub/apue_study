#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buff1[] = "abcdefghij";
char buff2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    if ((fd = creat("file.hole", 00700)) < 0)
        perror("creat");

    if (write(fd, buff1, 10) != 10)
        perror("buff1 write");

    if (lseek(fd, 16384, SEEK_SET) == -1)
        perror("lseek");

    if (write(fd, buff2, 10) != 10)
        perror("buff2 write");

    exit(0);
}
