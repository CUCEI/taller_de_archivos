#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des, tot;
    char caracter;
    des = open("C:\\tmp\\archivo",0);
    if(des>0)
    {
        read(des, &caracter, 1);
        printf("%c", caracter);

        lseek(des, (tot-1), 0);
        read(des, &caracter, 1);
        printf("%c", caracter);
    }
    else
        perror(" ");
    return 0;
}
