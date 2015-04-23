#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;

    if (argc != 2)
    {
        printf("wrong argument!\n");
        exit(-1);
    }
    
    if (chdir(argv[1])< 0)
    {
        perror("chdir");
    }
    
    fd = open("xukai", O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd < 0)
    {
        perror("open");
    }
    
    return 0;
}
