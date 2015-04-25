#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

int main(int argc, const char *argv[])
{
    uid_t uid = 0;
    struct passwd *ptr;

    if (argc != 2)
    {
        printf("wrong argument\n");
        exit(-1);
    }

    uid = atoi(argv[1]);

    if ((ptr = getpwuid(uid)) != NULL)
    {
        printf("name = %s\tpasswd = %s\tuid = %d, gid = %d\n", \
                ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid);
        printf("comment = %s\tdir = %s\tshell = %s\n", \
                ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
    }
    else
    {
        printf("there is no uid %d\n", uid); 
        exit(-1);
    }

    return 0;
}
