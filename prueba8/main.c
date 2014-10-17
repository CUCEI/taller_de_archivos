#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des, act=1;
    char caracter;
    des = open("C:\\tmp\\archivo",2);
    if(des>0)
    {
        while(act>0)
        {
            lseek(des, 2,1);
            act = read(des, &caracter, 1);
            printf("%c", caracter);
        }

    }
    else
        perror(" ");
    return 0;
}
