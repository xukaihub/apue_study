#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("wrong argument!\n");
        exit(-1);
    }

    if (rmdir(argv[1]) < 0)
    {
        perror("rmdir"); 
    }
    
    return 0;
}
