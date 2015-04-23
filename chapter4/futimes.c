#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0)
        {
            printf("%s: stat error", argv[i]);
            continue;
        }

        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
        {
            printf("%s: open error", argv[i]);
            continue;
        }

        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;

        if (futimens(fd, times) < 0)
            printf("%s: futimens error", argv[i]);

        close(fd);
    }
    
    return 0;
}
