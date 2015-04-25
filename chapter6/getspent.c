#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main(void)
{
    struct spwd *ptr;

    setspent();
    
    while ((ptr = getspent()) != NULL)
    {
        printf("name= %s\tshaow passwd = %s\n", ptr->sp_namp, ptr->sp_pwdp);
    }

    endspent();

    return 0;
}
