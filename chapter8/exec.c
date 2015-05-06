#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        if (execle("/home/xukai/echoall", "echoall",
                    "myarg1", "MY ARG2", (char *)0, env_init) < 0)
        {
            perror("execle");
        }
    }

    if (waitpid(pid, NULL, 0) < 0)
    {
        perror("waitpid");
    }
   
    if ((pid = fork()) < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
        {
            perror("execlp");
        }
    }
    
    exit(0);
}
