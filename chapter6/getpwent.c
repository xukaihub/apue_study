#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, const char *argv[])
{
    struct passwd *ptr;

    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }
 
    setpwent();

    while ((ptr = getpwent()) != NULL)
    {
        if (strcmp(argv[1], ptr->pw_name) == 0)
        {
            printf("name = %s\tpasswd = %s\tuid = %d, gid = %d\n", \
                    ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid);
            printf("comment = %s\tdir = %s\tshell = %s\n", \
                    ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
            break;
        }
    }
   
    endpwent();

    return 0;
}
