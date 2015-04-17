#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    {
        printf("cannot seek!\n");
        perror("lseek");
    }
    else
        printf("seek ok!\n");

    exit(0);
}
