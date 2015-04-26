#include <stdio.h>
#include <unistd.h>

#define NAME_LEN 64

int main(void)
{
    char name[NAME_LEN];

    if (gethostname(name, NAME_LEN) < 0)
    {
        perror("gethostname"); 
    }
    
    printf("%s\n", name);

    return 0;
}
