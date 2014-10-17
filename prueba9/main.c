#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int nuevo;
    nuevo = creat("archivo",755);
    if(nuevo>0)
        write(nuevo,"Hola mundo", 10);
    else
        perror(" ");
    return 0;
}
