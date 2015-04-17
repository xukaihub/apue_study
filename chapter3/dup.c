#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE     512 

static const char buf[BUFSIZE] = "Hello, dup!\n";

int main(void)
{
    int fd;
    int len;

    fd = dup(1);
    
    len = strlen(buf);

    if (write(fd, buf, len) != len)
        perror("write");

    exit(0);
}
