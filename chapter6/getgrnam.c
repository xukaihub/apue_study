#include <stdio.h>
#include <stdlib.h>
#include <grp.h>

int main(int argc, const char *argv[])
{
    struct group *ptr;

    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    if ((ptr = getgrnam(argv[1])) != NULL)
    {
        printf("name = %s, passwd =%s, gid = %d\n", ptr->gr_name, ptr->gr_passwd, ptr->gr_gid);
         
        printf("group member:\n"); 
        while (*ptr->gr_mem != NULL)
        {
            printf("%s\n", *ptr->gr_mem);
            ptr->gr_mem++;
        }
    }
    else
    {
        printf("there is no group name %s\n", argv[1]);
    }
    
    return 0;
}
