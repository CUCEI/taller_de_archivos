#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des;
    des = open("C:\\tmp\\archivo",0);
    if(des>0)
        printf("apertura exitosa");
    else
        perror(" ");
    return 0;
}
