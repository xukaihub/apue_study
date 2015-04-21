#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("wrong argumen!\n");
        exit(-1);
    }
    
    if (rename(argv[1], argv[2]) < 0)
    {
        perror("rename");
    }
    
    return 0;
}
