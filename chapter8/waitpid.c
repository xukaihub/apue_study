#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        if ((pid = fork()) < 0)
        {
            perror("fork");
        }
        else if (pid > 0)
        {
            exit(0);
        }
        
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getpid());
        exit(0);
    }
    
    if (waitpid(pid, NULL, 0) != pid)
    {
        perror("waitpid");
    }
    
    exit(0);
}
