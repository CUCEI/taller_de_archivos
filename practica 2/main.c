#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    char caracter;
    fd = open("arch",0);
    if(fd>0)
    {
        read(fd, &caracter, 1);
            printf("%c", caracter);
    }
    else
        perror(" ");
    return 0;
}
