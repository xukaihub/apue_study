#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        printf("wrong argument");
        exit(-1);
    }
    
    if (unlink(argv[1]) < 0)
    {
        perror("unlink");
    }

    return 0;
}
