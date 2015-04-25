#include <stdio.h>
#include <stdlib.h>
#include <grp.h>

int main(int argc, const char *argv[])
{
    int gid = 0;
    struct group *ptr;

    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
    
    gid = atoi(argv[1]);
    if ((ptr = getgrgid(gid)) != NULL)
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
        printf("there is no group id %d\n", gid);
        exit(-1);
    }
        
    return 0;
}
