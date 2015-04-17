#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512
static const char buf[BUFSIZE] = "Hello, dup2\n";

int main(void)
{
    int fd_new = 12;
    int len;

    if (dup2(1, fd_new) != fd_new)
    {
        perror("dup2");
    }

    len = strlen(buf);

    if (write(fd_new, buf, len) != len)
    {
        perror("write");
    }

    return 0;
}
