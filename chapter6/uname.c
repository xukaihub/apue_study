#include <stdio.h>
#include <sys/utsname.h>

int main(void)
{
    struct utsname ptr;
    
    if (uname(&ptr) < 0)
    {
        perror("uname"); 
    }
    
    if (&ptr != NULL)
    {
        printf("%s %s %s %s %s\n", \
                ptr.sysname, ptr.nodename, ptr.release,\
                ptr.version, ptr.machine);
    }

    return 0;
}
