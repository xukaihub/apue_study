#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    for (i = 1; i < argc; i++)
    {
        if (putenv(argv[i]) != 0)
        {
            perror("perror");
        }
    }
    
    return 0;
}
