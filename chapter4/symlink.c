#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("wrong argument!\n");
        exit(-1);
    }

    if (symlink(argv[1], argv[2]) < 0)
    {
        perror("symlink");
    }
    
    
    return 0;
}
