#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("wrong argument!\n");
        exit(-1);
    }

    if (mkdir(argv[1], 0777) < 0)
    {
        perror("mkdir"); 
    }
    
    return 0;
}
