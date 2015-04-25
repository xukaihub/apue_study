#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

int main(int argc, const char *argv[])
{
    struct passwd *ptr;

    if (argc != 2)
    {
        printf("wrong argument");
        exit(-1);
    }
    
    if ((ptr = getpwnam(argv[1])) != NULL)
    {
        printf("name = %s\tpasswd = %s\tuid = %d, gid = %d\n", \
                ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid);
        printf("comment = %s\tdir = %s\tshell = %s\n", \
                ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
    }
    else
    {
        printf("there is no username %s", argv[1]);
        exit(-1);
    }
    
    return 0;
}
