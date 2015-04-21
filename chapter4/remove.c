#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    if (remove(argv[1]) < 0)
    {
        perror("remove");
    }
    
    return 0;
}
