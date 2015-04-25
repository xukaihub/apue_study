#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int i;
    struct stat buf;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if (stat(argv[i], &buf) < 0)
        {
            printf("stat error\n");
            continue;
        }

        printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
        
        if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
        {
            printf(" (%s) rdev = %d/%d", \
                    (S_ISCHR(buf.st_mode)) ? "characher" : "block",\
                    major(buf.st_rdev), minor(buf.st_rdev));
        }
        printf("\n"); 
    }
    
    return 0;
}
