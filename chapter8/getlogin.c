#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("login name = %s\n", getlogin());

    return 0;
}
