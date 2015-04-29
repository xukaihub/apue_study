#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int i;
    char *ptr;

    if (argc < 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    for (i = 1; i < argc; i++)
    {
        ptr = getenv(argv[i]);
        if (NULL == ptr)
            continue;
        
        printf("%s: %s\n", argv[i], ptr);
    }
    
    return 0;
}
