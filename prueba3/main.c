#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int nuevo, abrir;
    nuevo = creat("C:\\tmp\\archivo",210);
    abrir = open("C:\\tmp\\archivo",1);
    if(abrir>0)
        printf("Apertura exitosa");
    else
        perror(" ");
    return 0;
}
