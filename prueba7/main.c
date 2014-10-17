#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des, tot;
    char caracter[10];
    des = open("C:\\tmp\\archivo",0);
    if(des>0)
    {
        tot=lseek(des,0,2);
        if(tot>=10)
        {
            lseek(des,0,0);
            read(des, &caracter, 10);
            caracter[10]='\0';
            printf("%s", caracter);
        }
        else
            printf("El archivo solo tiene  %i caracteres", tot);
    }
    else
        perror(" ");
    return 0;
}
