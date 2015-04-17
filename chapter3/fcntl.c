#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

static const char buf[BUFSIZE] = "Hello, fcntl!\n";

int main(void)
{
    int fd_old;
    int fd;
    int len;
    int flag;
   
    fd_old = open("test.txt", O_WRONLY | O_NDELAY | O_FSYNC | O_CREAT | O_TRUNC, 00777);
    if (fd_old < 0)
    {
        perror("open");
    }

    /* dump fd */
    printf("dump fd\n");
    fd = fcntl(fd_old, F_DUPFD, 0);
    
    if (fd < 0)
    {
        perror("fcntl");
    }
    
    len = strlen(buf);
    if (write(fd, buf, len) != len)
    {
        perror("write");
    }

     /* dump fd to specific num */
    printf("dump fd to specific num\n");
    printf("Dump fd to 12\n");

    fd = fcntl(fd_old, F_DUPFD, 12);
    
    printf("fd = %d\n", fd);

    /* get TFD and set TFD*/
    printf("get TFD and set TFD\n");
    flag = fcntl(fd, F_GETFD, 0);
    printf("TFD = %d\n", flag);
    
    flag |= FD_CLOEXEC;
    fcntl(fd, F_SETFD, flag);

    flag = 0;
    flag = fcntl(fd, F_GETFD);

    printf("new TFD = %d\n", flag);

    /* get TFL and set TFL */
    printf("get TFL and set TFL\n");
    flag = 0;
    flag = fcntl(fd, F_GETFL, 0);
    printf("TFL = %d\n", flag);
    printf("ACCMODE = %d\n", flag & O_ACCMODE);






    return 0;
}
