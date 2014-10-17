#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des, cant, rcant;
    char caracter[100];
    des = open("C:\\tmp\\archivo",0);
    printf("Dame la cantidad de bytes a leer: ");
    scanf("%i", &cant);
    if(des>0)
    {

        while((rcant=read(des, &caracter, cant))>0)
        {
            caracter[rcant] = '\0';
            printf("%s", caracter);
        }
    }
    else
        perror(" ");
    return 0;
}
