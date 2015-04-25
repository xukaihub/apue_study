#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main(int argc, const char *argv[])
{
    struct spwd *ptr;
    
    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    if ((ptr = getspnam(argv[1])) != NULL)
    {
        printf("shaow passwd = %s\n", ptr->sp_pwdp);
    }
    else
    {
        printf("there is no username %s\n", argv[1]);    
        exit(-1);
    }
     
    return 0;
}
