#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des;
    des = creat("archivo.nada",755);
    if(des>0)
        printf("creacion exitosa");
    else
        perror(" ");
    return 0;
}
