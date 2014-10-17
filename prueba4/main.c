#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des;
    char caracter;
    des = open("C:\\tmp\\archivo",2);
    if(des>0)
    {

        while(read(des, &caracter, 1)>0)
            printf("%c", caracter);
    }
    else
        perror(" ");
    return 0;
}
