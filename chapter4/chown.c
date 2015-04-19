#include <stdio.h>
#include <unistd.h>

int main(void)
{
    /* change foo file own:grp = root:root */
    if (chown("foo", 0, 0) < 0)
    {
        perror("chow");
    }
    
    return 0;
}
