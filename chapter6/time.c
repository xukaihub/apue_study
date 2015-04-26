#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t current_time;
    
    if (time(&current_time) < 0)
    {
        perror("time"); 
    }
    
    printf("%ld\n", current_time);

    return 0;
}
