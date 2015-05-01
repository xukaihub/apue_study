#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("pid = %d, ppid = %d, uid = %d, euid = %d, gid = %d, egid =%d\n", 
            getpid(), getppid(), getuid(), geteuid(), getgid(), getegid());
    return 0;
}
